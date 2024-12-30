# Google DeepMind Code Contests Dataset Refinement

To enhance the accuracy and efficiency of the [Google DeepMind Code Contests](https://github.com/google-deepmind/code_contests) dataset, apply the following refinements:

- **Code Formatting**  
  - Reformat C++ code to follow the Google `clang-format` style.
  - Reformat Python code to adhere to `PEP8` standards.

- **Solution Pairing**  
  - Pair correct and incorrect solutions to form training examples.

- **Filtering Criteria**  
  - Filter out correct code that fails any private or public test cases.
  - Filter out incorrect code that passes all test cases.

- **Test Case Selection**  
  - Choose test cases that all filtered correct code passes.
  - Select test cases where the pass rate of incorrect code is below 70%.

These steps will be applied to the dataset located in the `deepmind_codecontests_refine` folder.


## Dataset Curation
```bash
bash make_folder.sh

python dataset_curation.py --language python --data_split valid
python dataset_curation.py --language python --data_split test
python dataset_curation.py --language python --data_split train

python dataset_curation.py --language cpp --data_split valid
python dataset_curation.py --language cpp --data_split test
python dataset_curation.py --language cpp --data_split train
```
### Cpp correct solution execution
```bash
python cpp_test_gold_filter.py
python cpp_valid_gold_filter.py
python cpp_train_gold_filter.py
```
### Python3 correct solution execution
```bash
python python_test_gold_filter.py
python python_valid_gold_filter.py
python python_train_gold_filter.py
```
### Generating filtered Test case data w.r.t. Correct solution
```bash
python cpp_gold_filter.py
python python_gold_filter.py
```

### Cpp incorrect solution execution
```bash
python cpp_test_source_filter.py
python cpp_valid_source_filter.py
python cpp_train_source_filter.py
```
### Python3 incorrect solution execution
```bash
python python_test_source_filter.py
python python_valid_source_filter.py
python python_train_source_filter.py
```
### Generating filtered Test case data w.r.t. Incorrect solution
```bash
python cpp_source_filter.py
python python_source_filter.py
```
### # of Data(cpp)
```python
# Original test case of test_check_result 33634
# Original test case of valid_check_result 23924
# Original test case of train_check_result 1276989
# Original Code pair of test_check_result 1664
# Original Code pair of valid_check_result 1407
# Original Code pair of train_check_result 199441

# Gold filtered test case of test_check_result 30746
# Gold filtered test case of valid_check_result 22277
# Gold filtered test case of train_check_result 811105
# Gold filtered Code pair of test_check_result 1389
# Gold filtered Code pair of valid_check_result 1115
# Gold filtered Code pair of train_check_result 174125

# source filtered test case of test_check_result 17152
# source filtered test case of valid_check_result 12214
# source filtered test case of train_check_result 392984
# source filtered Code pair of test_check_result 1052
# source filtered Code pair of valid_check_result 830
# source filtered Code pair of train_check_result 110158
```

### # of Data(python)
```python
# Original test case of test_check_result 33634
# Original test case of valid_check_result 23924
# Original test case of train_check_result 1276989
# Original Code pair of test_check_result 1134
# Original Code pair of valid_check_result 1048
# Original Code pair of train_check_result 520124

# Gold filtered Test case of test_check_result 35446
# Gold filtered Test case of valid_check_result 12737
# Gold filtered Test case of train_check_result 526205
# Gold filtered Code pair of test_check_result 1932
# Gold filtered Code pair of valid_check_result 769
# Gold filtered Code pair of train_check_result 477993

# source filtered test case of test_check_result 21553
# source filtered test case of valid_check_result 8158
# source filtered test case of train_check_result 304214
# source filtered Code pair of test_check_result 1820
# source filtered Code pair of valid_check_result 621
# source filtered Code pair of train_check_result 358209
```


Final data will be saved in *cpp_data* and *python_data* folder
### Choose 10 Test Cases per each code pairs
```bash
python test_case_select.py
```

# Variable Trace - Cpp & Python Data
Code is in variable_trace folder

~~### g++ / gdb version~~
```
g++-7 (Ubuntu 7.5.0-6ubuntu2) 7.5.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
```
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04.2) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

~~## How to trace - cpp~~
~~### **g++ Compile Option**~~
```bash
g++-7 <cpp_filename> -o <compile_filename> -ggdb -O0
```

~~### **Variable Trace**~~
```bash
gdb <compile_filename>
(gdb) source trace.py
(gdb) trace <symbol_file> <cpp_filename> <save_filename> <input_filename>
```

~~### **Demo Usage**~~
```bash
g++-7 cpp_correct_test_0_0.cpp -o test -ggdb -O0
gdb test
(gdb) source trace.py
(gdb) trace user_def.txt cpp_correct_test_0_0.cpp test_save input.txt
```
~~#### Symbol_file contains the variable name that we have to trace.~~
~~#### After this command traced file test_save.json will be saved on base directory~~

~~#### Input of the cpp file is saved on './cpp_input' directory zip files.~~

## How to trace - Python
### Trace identifier values
```bash
python python_test_multi_trace.py
python python_valid_multi_trace.py
python python_train_multi_trace.py
```
### Delete Loop & Generate Trace Summary
```bash
python generate_trace_added_data.py
```
### Select Single Test case per one code pair
```bash
python python_data_filter.py
```

*Final Data will be saved in python_data folder*

# Generating Actual Output for Automated Program Repair

To facilitate automated program repair, actual output data is incorporated. Additionally, trace data without meaningful information for training LLM is filtered. This data is derived from `python_final_trace_added_choose_1.json` and `python_final_trace_added.json`, which are generated through variable tracing.

- The final outputs are stored in the `./python_actual_output_gen` directory as `python_final_filtered_all.jsonl` and `python_final_filtered_single.jsonl`.

```bash
bash initialize.sh
python translate.py

python save_actual_output.py --single_multiple single
python save_actual_output.py --single_multiple multiple

python python_data_filter.py
```

### Final data length (Single test case per each code pair)
```
single data length = 263764                                                                                                        
filtered single data length = 173723    
```

### Final data length (multiple test case per each code pair)
```
multiple data length = 2596591                                                                                                          
filtered multiple data length = 1714111 
```