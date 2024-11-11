from math import *
from bisect import *

def update(bit, size, idx, amount):
    while idx <= size:
        if bit[idx] < amount:
            bit[idx] = amount
        idx += idx & -idx

def read(bit, idx):
    rst = 0
    while idx >= 1:
        if bit[idx] > rst:
            rst = bit[idx]
        idx -= idx & -idx
    return rst

n = int(input())
arr = [map(int, input().split()) for _ in range(n)]
arr = [r*r*h for r, h in arr]

arr2 = sorted(list(set(arr)))
n2 = len(arr2)
bit = [0] * (n2 + 1)

for v in arr:
    idx = bisect(arr2, v)
    update(bit, n2, idx, read(bit, idx-1) + v)

print(pi*max(bit))
