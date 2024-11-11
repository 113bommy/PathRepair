# coding=utf-8 
# Created by TheMisfits 
from sys import stdin
_input = stdin.readline
_int, _range = int, range
def solution():
    n, k = [_int(i) for i in _input().split()]
    arr = [_int(i) for i in _input().split()]
    arr.sort()
    ans = 0
    for i in _range(2, n, 3):
        if arr[i] + k <= 5:
            ans += 1
    print(ans)
solution()