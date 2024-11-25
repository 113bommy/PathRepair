import json
import os
import sys
import argparse

def read_json(path):
    with open(path, 'r') as f:
        json_data = json.load(f)
    return json_data

def save_json(file, path):
    with open(path, 'w') as f:
        json.dump(file, f, indent = 4)

def count_code(py_dict):
    count = 0
    for key, value in py_dict.items():
        count += len(value['code_pair'])
    return count

if __name__ == "__main__":
    # Choose Language to split data
    parser = argparse.ArgumentParser()
    parser.add_argument('--language', type = str, default = 'python')
    args = parser.parse_args()
    language = args.language
    
    base_path = os.getcwd()
    language_dict = {}
    data_type = ['train', 'test', 'valid']
    code_count = 0

    # Gather all the data 
    for dt in data_type:
        single_data_path = os.path.join(base_path, f'./{language}_data/{language}_{dt}_case_10.json')
        single_data = read_json(single_data_path)
        print(single_data.keys())
        print(len(single_data.keys()))
        for pid, pid_dataset in single_data.items():
            language_dict[f'{dt}_{pid}'] = pid_dataset
            
        code_count += len(pid_dataset['code_pair'])
            
    print(f'Total PID = {len(language_dict.keys())}')
    print(f'Total Code = {code_count}')

    save_json(language_dict, os.path.join(base_path, f'{language}_data', f'{language}_test_case_10_concat.json'))