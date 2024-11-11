from tqdm import tqdm
import json
import os
import numpy as np

def find_test_case_length(dic):
    len_dict = {}
    for key in dic.keys():
        len_public_test_case = len(dic[key]['test_case']['public']['input'])
        len_private_test_case = len(dic[key]['test_case']['private']['input'])
        len_generated_test_case = len(dic[key]['test_case']['generated']['input'])
        len_dict[key] = [len_public_test_case, len_private_test_case, len_generated_test_case]

    return len_dict

def concat_test_case(dic):
    for key in dic.keys():
        dic[key]['test_case'] = {
            'input':[*dic[key]['test_case']['public']['input'], *dic[key]['test_case']['private']['input'], *dic[key]['test_case']['generated']['input']],
            'output':[*dic[key]['test_case']['public']['output'], *dic[key]['test_case']['private']['output'], *dic[key]['test_case']['generated']['output']]
        }

    return dic

def make_numpy(result_json):
    result = result_json['results']
    code_index_list = []
    test_result_list = []
    for single_result in result:
        code_index_list.append(single_result[0])
        test_result_list.append(single_result[1])
    np_test_result = np.array(test_result_list)

    return (code_index_list, np_test_result)

# Selecting appropriate correct codes and test cases

def refine_data(code_index_list, np_test_result, len_list):
    len_public = len_list[0]
    len_private = len_list[1]

    test_length = len_public + len_private

    if (len(code_index_list) != np_test_result.shape[0]):
        adsfasf 
    non_zero_indices = np.where(np.all(np_test_result[:, range(test_length)] != 0, axis=1))[0]
    gold_code_index = [code_index_list[gold_index] for gold_index in non_zero_indices]
    np_gold_code = np_test_result[non_zero_indices]
    test_case_index = np.where(np.all(np_gold_code != 0, axis=0))[0]

    return test_case_index, gold_code_index

def check_result(result_path, len_dict):
    final_test_case = {}
    
    for index, check_file in tqdm(enumerate(os.listdir(result_path)), leave = True):
        pid = check_file.split('_')[-1].split('.json')[0] 
        file_path = os.path.join(result_path, check_file)
        with open(file_path, 'r') as f:
            result_json = json.load(f)

        code_index_list, np_test_result = make_numpy(result_json)
        test_case_index, gold_code_index = refine_data(code_index_list, np_test_result, len_dict[pid])

        final_test_case[pid] = [test_case_index.tolist(), gold_code_index]

    return final_test_case

def extract_values(indices, raw_test_case, raw_code_pair):
    input_values = raw_test_case['input']
    output_values = raw_test_case['output']
    
    test_case_refine = {
        'input': [input_values[i] for i in indices[0]],
        'output': [output_values[i] for i in indices[0]]
    }
    code_refine = [raw_code_pair[j] for j in indices[1]]

    return test_case_refine, code_refine

def data_filter(final_test_case, data_dict):

    final_test_case_key = final_test_case.keys()

    for key, value in final_test_case.items():
        raw_test_case = data_dict[key]['test_case']
        raw_code_pair = data_dict[key]['code_pair']
        extract_test_case, extract_code = extract_values(value, raw_test_case, raw_code_pair)
        data_dict[key]['test_case'] = extract_test_case
        data_dict[key]['code_pair'] = extract_code

    for key, value in data_dict.items():    
        if key not in final_test_case_key:
            data_dict[key]['test_case'] = {
                'input': [],
                'output': []
            }
    
    del_dict = []

    for key, value in data_dict.items():
        if (len(value['test_case']['input']) == 0) & (len(value['test_case']['output']) == 0):
            del_dict.append(key)
            continue
        if len(value['code_pair']) == 0:
            del_dict.append(key)
            continue

    for del_key in del_dict:
        del data_dict[del_key]

    return data_dict 

def count_test_case(python_dict):
    count = 0
    for key, value in python_dict.items():
        count += len(value['test_case']['input'])
    return count

def count_code(python_dict):
    count = 0
    for key, value in python_dict.items():
        if len(value['test_case']['input']) != 0:
            count += len(value['code_pair'])

    return count

np.set_printoptions(threshold=np.inf)
curr_path = os.getcwd()

python_test_result_path = os.path.join(curr_path, 'python_test_gold_result')
python_valid_result_path = os.path.join(curr_path, 'python_valid_gold_result')
python_train_result_path = os.path.join(curr_path, 'python_train_gold_result')

python_test_refine_path = os.path.join(curr_path, 'python_data', 'python_test_refine.json')
python_valid_refine_path = os.path.join(curr_path, 'python_data', 'python_valid_refine.json')
python_train_refine_path = os.path.join(curr_path, 'python_data', 'python_train_refine.json')

with open(python_test_refine_path, 'r') as f:
    python_test = json.load(f)
with open(python_valid_refine_path, 'r') as f:
    python_valid = json.load(f)
with open(python_train_refine_path, 'r') as f:
    python_train = json.load(f)

len_python_test = find_test_case_length(python_test)
len_python_valid = find_test_case_length(python_valid)
len_python_train = find_test_case_length(python_train)

python_test = concat_test_case(python_test)
python_valid = concat_test_case(python_valid)
python_train = concat_test_case(python_train)

test_check_result = check_result(python_test_result_path, len_python_test)
valid_check_result = check_result(python_valid_result_path, len_python_valid)
train_check_result = check_result(python_train_result_path, len_python_train)

print(f'# Original test case of test_check_result {count_test_case(python_test)}')
print(f'# Original test case of valid_check_result {count_test_case(python_valid)}')
print(f'# Original test case of train_check_result {count_test_case(python_train)}')

print(f'# Original Code pair of test_check_result {count_code(python_test)}')
print(f'# Original Code pair of valid_check_result {count_code(python_valid)}')
print(f'# Original Code pair of train_check_result {count_code(python_train)}')

gold_filter_test = data_filter(test_check_result, python_test)
gold_filter_valid = data_filter(valid_check_result, python_valid)
gold_filter_train = data_filter(train_check_result, python_train)

print(f'# Gold filtered test case of test_check_result {count_test_case(gold_filter_test)}')
print(f'# Gold filtered test case of valid_check_result {count_test_case(gold_filter_valid)}')
print(f'# Gold filtered test case of train_check_result {count_test_case(gold_filter_train)}')

print(f'# Gold filtered Code pair of test_check_result {count_code(gold_filter_test)}')
print(f'# Gold filtered Code pair of valid_check_result {count_code(gold_filter_valid)}')
print(f'# Gold filtered Code pair of train_check_result {count_code(gold_filter_train)}')

with open(f'./python_data/python_test_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_test, f, indent=None)

with open(f'./python_data/python_valid_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_valid, f, indent=None)

with open(f'./python_data/python_train_gold_filtered.json', 'w') as f:
    json.dump(gold_filter_train, f, indent=None)