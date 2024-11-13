import json
import subprocess
import multiprocessing
import glob
import os
import chardet
import pandas as pd
import numpy as np
from math import isclose
from tqdm import tqdm
from multiprocessing import Pool
from typing import Union

def concat_test_case(dic):
    for key in dic.keys():
        dic[key]['test_case'] = {
            'input':[*dic[key]['test_case']['public']['input'], *dic[key]['test_case']['private']['input'], *dic[key]['test_case']['generated']['input']],
            'output':[*dic[key]['test_case']['public']['output'], *dic[key]['test_case']['private']['output'], *dic[key]['test_case']['generated']['output']]
        }
    return dic

def make_cpp_file(pid, index, code):
    with open(f'./cpp_gold_filter_file/cpp_test_{pid}_{index}.cpp', 'w') as f:
        f.write(code)

def is_float(value):
    try:
        float(value)
        return True
    except ValueError:
        return False
        
def compare_outputs(actual_out, expect, partial=False):
    yes_no_list = ['Yes', 'No', 'YES', 'NO', 'yes', 'no']
    if partial:
        expect = expect[: len(actual_out)]
    actual_list = actual_out.strip().split()
    excepted_list = expect.strip().split()
    if len(actual_list) != len(excepted_list):
        return False
    
    for actual_com, expected_com in zip(actual_list, excepted_list):
        if is_float(actual_com) and is_float(expected_com):
            if not isclose(float(actual_com), float(expected_com), rel_tol = 1e-6):
                return False
        elif (actual_com in yes_no_list) & (expected_com in yes_no_list):
            if not (actual_com.lower() == expected_com.lower()):
                return False
        else:
            if not actual_com == expected_com:
                return False
            
    return True

def decode_output(output):
    result = chardet.detect(output)
    encoding = result['encoding']
    if not encoding:
        return output
    try:
        return output.decode(encoding)
    except (UnicodeDecodeError, AttributeError):
        return output  

def run_test_cases(file, input_data_list, expected_output_list):
    correct_test = 0
    num_partial = 0
    output_list = []
    for index, data in enumerate(input_data_list):
        cpp_input = data
        partial = False
        try:
            process = subprocess.run(
                [f"./cpp_compile/{file}"], input=cpp_input, text=True, errors="replace", capture_output=True, timeout=2
            )
            try:
                if isinstance(process.stdout, bytes):
                    decoded_output = decode_output(process.stdout)
                    actual_output = repr(decoded_output.strip())
                else:
                    actual_output = repr(process.stdout.strip())
            except Exception as decode_error:
                actual_output = "<decoding error>"
                print(f"Decoding error for process output: {decode_error}")
        except subprocess.TimeoutExpired as e:
            if e.stdout:
                try:
                    if isinstance(e.stdout, bytes):
                        decoded_output = decode_output(e.stdout)
                        actual_output = repr(decoded_output.strip())
                    else:
                        actual_output = repr(e.stdout.strip())
                except Exception as decode_error:
                    actual_output = "<decoding error>"
                    print(f"Decoding error for timeout process output: {decode_error}")
                num_partial += 1
                process = e
                partial = True
            else:
                actual_output = ""
                partial = False

        expected = expected_output_list[index]
        actual = actual_output
        
        try:
            expect = expected.replace('\\n', ' ')
        except AttributeError:
            pass
        try:
            actual = actual.replace('\\n', ' ')
        except AttributeError:
            pass
        try:
            expect = expect.replace('\\t', ' ')
        except AttributeError:
            pass
        try:
            actual = actual.replace('\\t', ' ')
        except AttributeError:
            pass

        expect = expect.strip()
        actual_save = actual
        actual = actual[1:-1]
        expect = expect
        actual = actual.strip()

        if compare_outputs(actual, expect, partial=partial):
            output_list.append(1)
            correct_test += 1
        else:
            output_list.append(0)

    return output_list

def compile_and_test(pid_index_codes):
    pid, index, codes = pid_index_codes
    make_cpp_file(pid, index, codes)

    compiled_file_path = f"./cpp_compile/cpp_test_{pid}_{index}"
    compile_result = subprocess.run(
        ["g++-7", "-std=c++11", "-static", '-O2', "-o", compiled_file_path, f'./cpp_gold_filter_file/cpp_test_{pid}_{index}.cpp'],
        capture_output=True
    )

    if compile_result.returncode != 0:
        with open(f'./cpp_result/exclude_test_gold.txt', "a", encoding='utf-8') as err_log_file:
            err_log_file.write(f"cpp_test_{pid}_{index}\n")
        return (pid, index, False, compiled_file_path)

    input_list = cpp_test[pid]['test_case']['input']
    output_list = cpp_test[pid]['test_case']['output']
    success_check = run_test_cases(f"cpp_test_{pid}_{index}", input_list, output_list)
    return (pid, index, success_check, compiled_file_path)

def save_results(pid, results):
    try:
        with open(f'./cpp_test_gold_result/cpp_test_check_{pid}.json', 'r+') as f:
            existing_results = json.load(f)
            existing_results['results'].extend(results)
            f.seek(0)
            json.dump(existing_results, f, indent=None)
            f.truncate()
    except FileNotFoundError:
        with open(f'./cpp_test_gold_result/cpp_test_check_{pid}.json', 'w') as f:
            json.dump({'results': results}, f, indent=None)

def delete_compiled_file(compiled_file_path):
    os.remove(compiled_file_path)

def process_result(result):
    pid, index, success_check, compiled_file_path = result
    if success_check is not False: 
        save_results(pid, [(index, success_check)])
        delete_compiled_file(compiled_file_path) 

def delete_all_files_in_folder(folder_path):
    for file_path in glob.glob(os.path.join(folder_path, "*")):
        try:
            os.remove(file_path) 
            print(f"Deleted: {file_path}")
        except Exception as e:
            print(f"Error deleting {file_path}: {e}")
            
if __name__ == "__main__":
    delete_all_files_in_folder('./cpp_test_gold_result')
    with open('./cpp_data/cpp_test_refine.json', 'r') as f:
        cpp_test = json.load(f)

    cpp_test = concat_test_case(cpp_test)
    tasks = []

    for idx, (pid, value) in enumerate(list(cpp_test.items())):
        for index, codes in enumerate(value['code_pair']):
            tasks.append((pid, index, codes[0]))
            
    with multiprocessing.Pool(100) as pool:
        for result in tqdm(pool.imap_unordered(compile_and_test, tasks), total=len(tasks), ncols=60):
            process_result(result)