'''https://codeforces.com/problemset/problem/1131/C'''

from typing import List
from math import ceil


def seq(s: int, n: int) -> int:
    return s + (-1)**(n+1) * ceil(n / 2)


def solv(arr: List[int]) -> List[int]:
    arr.sort()
    rez = [0] * len(arr)
    m = (len(arr) - 1) // 2
    for i in range(len(arr)):
        j = seq(m, i)
        rez[j] = arr[i]

    return rez


input()
arr_txt = input()
arr = [int(v) for v in arr_txt.split()]
print(' '.join(map(str, solv(arr))))
