# https://codeforces.com/problemset/problem/960/B

from sys import stdin, exit
from typing import List, Tuple


# arr is sorted desc, after this func arr is still sorted
def flaten(arr: List[int], by: int):
    pass

_, k1, k2 = [int(v) for v in stdin.readline().rstrip().split()]
A = [int(v) for v in stdin.readline().rstrip().split()]
B = [int(v) for v in stdin.readline().rstrip().split()]

for i in range(len(A)):
    A[i] -= B[i]

A.sort(key=lambda x: abs(x), reverse=True)

last_value_index = []
last = abs(A[0])
for i in range(len(A)):
    A[i] = abs(A[i])
    if A[i] != last:
        last_value_index.append((i - 1, A[i]))
        last = A[i]

moves = k1 + k2
changes = [0] * len(A)
levels_reduced = 0

if len(last_value_index) > 0:
    while moves > 0 and A[0] != 0:
        left_edge = max(last_value_index[levels_reduced][0] - moves, -1)
        for i in range(last_value_index[levels_reduced][0], left_edge, -1):
            A[i] -= 1
            moves -= 1
            if moves == 0:
                break
        if last_value_index[levels_reduced][1] == A[0]:
            levels_reduced += 1
            if levels_reduced >= len(last_value_index):
                break
if levels_reduced >= len(last_value_index):
    i = 0
    while moves > 0 and A[-1] != 0:
        A[i] -= 1
        moves -= 1
        i = (i + 1) % len(A)

if moves > 0 and A[0] == 0:
    print(moves % 2)
    exit(0)

E = 0
for i in A:
    E += i ** 2
print(E)
