import sys
import math
from collections import defaultdict as ddict
from collections import deque
import heapq
from queue import Queue

fast_inp = lambda: sys.stdin.readline().split('\n')[0]
read_list = lambda: fast_inp().split(' ')
read_listi = lambda: list(map(int, fast_inp().split(' ')))
read_listf = lambda: list(map(float, fast_inp().split(' ')))
read_int = lambda: int(fast_inp())
read_float = lambda: float(fast_inp())
read = lambda: fast_inp()
DEBUG = True


def debug(**kwargs):
    if not DEBUG:
        return
    print('*' * 20)
    for k, v in kwargs.items():
        print(f'\t{k}:{v}\t')
    print('*' * 20)

def possible(arr: list, n: int, x: int) -> bool:
    freq = ddict(int)
    for i in range(n): freq[arr[i]] += 1
    for i in range(x):
        freq[arr[i]] -= 1
        if freq[arr[i]] == 0:
            del freq[arr[i]]
    if len(freq) == n - x:
        return True
    for i in range(x, n):
        freq[arr[i - x]] += 1
        freq[arr[i]] -= 1
        if freq[arr[i]] == 0:
            del freq[arr[i]]
        if len(freq) == n - x:
            return True
    return False


def solve() -> None:
    n = read_int()
    arr = read_listi()
    low = 0
    high = n - 1
    best = float('inf')
    while low <= high:
        mid = (low + high) // 2
        if possible(arr, n, mid):
            high = mid - 1
            best = mid
        else:
            low = mid + 1
    print(best)


t = 1
for _ in range(t):
    solve()