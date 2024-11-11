def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return [str(x) for x in stdin.readline().split()]


def dp():
    mem[1, v1] = v1
    for i in range(2, t + 1):
        for j in range(-500, 600):
            for k in range(-d, d + 1):
                mem[i, j] = max(mem[i, j], j + mem[i - 1, j + k])

    return


from sys import stdin
from collections import *
from math import ceil

v1, v2 = arr_inp(1)
t, d = arr_inp(1)
mem = defaultdict(lambda: float('-inf'))
dp()
# print(mem)
print(mem[t, v2])
