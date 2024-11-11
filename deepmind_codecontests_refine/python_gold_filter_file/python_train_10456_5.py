# @Author: Justin Hershberger
# @Date:   21-03-2017
# @Filename: 426B.py
# @Last modified by:   Justin Hershberger
# @Last modified time: 21-03-2017

#Justin Hershberger
#Py3.5

import fileinput

def check_matrix(m):
    first_half = []
    second_half = []
    for i in range(len(m) // 2):
        first_half.append(m[i])
    for j in range(len(m), len(m) // 2, -1):
        second_half.append(m[j-1])

    if (first_half == second_half):
        return first_half
    else:
        return -1;


if __name__ == '__main__':
    n,m = map(int, input().split())

    matrix = []
    for arg in range(n):
        matrix.append(input().split())

    if len(matrix) % 2 == 0:
        result = matrix
        num_rows = n
        while(result != -1):
            result = check_matrix(result)
            if result != -1:
                num_rows = len(result)
        print(num_rows)
    else:
        print(n)
    # print(matrix)
