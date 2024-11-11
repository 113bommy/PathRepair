import collections
import math
from sys import stdin


def get(t=int):
    lis = stdin.readline().strip().split()
    return list(map(t, lis))


def single_str():
    return get(str)[0]


n, k = get()
a = [i for i in range(1, n + 1)]
print(*list(reversed(a[:k + 1])) + a[k + 1:])
