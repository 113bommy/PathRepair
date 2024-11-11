# import numpy as np

def get_num_operations(m, x):
    if x < m: return big_number
    if x == m: return 0
    return 1 + get_num_operations(m, int(x / 2))


big_number = 10000000

n, k=map(int, input().split())
elements_array = list(map(int, input().split()))

answer_elements = set()
answer_elements.add(0)
for element in elements_array:
    while element > 0:
        answer_elements.add(element)
        element = int(element / 2)


max_element = int(max(elements_array))
best_result = big_number
for m in answer_elements:
    cur_results_array = list()
    k_elements = 0
    for element in elements_array:
        cur_operations = get_num_operations(m, element)
        # if cur_operations < big_number:
        #     k_elements += 1
        cur_results_array.append(cur_operations)
        # if k_elements == k:
        #     break
    
    cur_results_array.sort()
    cur_operations = sum(cur_results_array[:k])
    best_result = min(best_result, cur_operations)

print(best_result)