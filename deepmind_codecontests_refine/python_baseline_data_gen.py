from tqdm import tqdm
from transformers import RobertaTokenizer
import os
import json
import argparse

def read_json(path):
    with open(path, 'r') as f:
        json_data = json.load(f)
    return json_data

def save_json(file, path):
    with open(path, 'w') as f:
        json.dump(file, f, indent = 4)

def sep_string(code_str):
    lines = code_str.strip().split('\n')
    numbered_lines = []
    for i, line in enumerate(lines, start=1):
        numbered_lines.append(f"{i} {line} |||")
    return numbered_lines

def compare_code_strings(code_str_1, code_str_2):
    lines_1 = sep_string(code_str_1)
    lines_2 = sep_string(code_str_2)
    
    max_len = max(len(lines_1), len(lines_2))
    differences = []
    
    for i in range(max_len):
        line_1 = lines_1[i] if i < len(lines_1) else f"{i+1}  |||"
        line_2 = lines_2[i] if i < len(lines_2) else f"{i+1}  |||"
        
        content_1 = line_1.split(' ', 1)[1]
        content_2 = line_2.split(' ', 1)[1]
        
        if content_1 != content_2:
            differences.append(f'{i+1} {content_1}')
    
    return differences

def read_examples(filename):
    """Read examples from filename for DeepFix style training Line stmt Line stmt Line stmt ..."""
    examples = []

    with open(filename, 'r') as f:
        json_data = json.load(f)

    for index, single_data in enumerate(json_data):
        if type(single_data['statement']) != str:
            pass
        else:
            code = single_data['incorrect_code'].strip()
            stmt = single_data['statement'].strip()
            examples.append(
                Example(
                    idx=index,
                    source=code,
                    target=stmt,
                )
            )
    return examples


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--threshold", default=512, type=int)
    parser.add_argument("--language", default='python', type=str)
    args = parser.parse_args()
    threshold = args.threshold
    language = args.language
    tokenizer = RobertaTokenizer.from_pretrained("Salesforce/codet5-base")

    base_path = os.getcwd()
    data_path = os.path.join(base_path, f'{language}_data', f'{language}_test_case_10_concat.json')
    json_data = read_json(data_path)
    edit_distance_data = []
    
    for pid, value in tqdm(json_data.items(), leave = True):
        for single_code in value['code_pair']:
            correct_sep = sep_string(single_code[0])
            incorrect_sep = sep_string(single_code[1])
            correct_string = ' '.join(correct_sep)
            incorrect_string = ' '.join(incorrect_sep)
            statement_string = ' '.join(compare_code_strings(single_code[0], single_code[1]))

            input_hf = tokenizer(incorrect_string, truncation=False)
            source_ids = input_hf.input_ids

            if (len(source_ids) > threshold):
                continue

            edit_distance_data.append({
                'pid': pid,
                'correct_code': correct_string,
                'incorrect_code': incorrect_string,
                'statement': statement_string,
                'test_case': value['test_case'],
                'raw_correct': single_code[0],
                'raw_incorrect': single_code[1]
            })
    print(len(edit_distance_data))    
    
    save_json_path = os.path.join(base_path, 
                                  f'{language}_data', 
                                  f'{language}_final_token_{threshold}.json')
    save_json(edit_distance_data, save_json_path)

if __name__ == "__main__":
    main()


