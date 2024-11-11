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
python ./python/python_test_multi_trace.py
python ./python/python_valid_multi_trace.py
python ./python/python_train_multi_trace.py
```
### Delete Loop & Generate Trace Summary
```bash
python ./python/generate_trace_added_data.py
```
### Select Single Test case per one code pair
```bash
python ./python/python_data_filter.py
```

*Final Data will be saved in python_data folder*

# Adding Actual Output for Automated Program Repair

To support automated program repair, actual output data is added. This data is generated using `final_adjustment.json` information created through variable tracing.

- Each code pair retains trace information for one test case.
- The final output is saved in the `./python_actual_output_gen` directory as `final_data_test.jsonl`.

```bash
bash make_folder.sh
python translate.py

python save_actual_output_test.py
python save_actual_output_valid.py
python save_actual_output_train.py

python python_data_filter.py
```
