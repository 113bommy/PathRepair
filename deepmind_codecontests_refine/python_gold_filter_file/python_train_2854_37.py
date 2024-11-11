from sys import *
from math import *
from sys import stdin,stdout
from collections import *

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)

n = int(input())
arr = int_arr()
if n <= 2:
    print(n)
else:
    mx = 0
    ct = 2
    for i in range(2,n):
        if arr[i] == arr[i - 1] + arr[i - 2]:
            ct += 1
        else:
            ct = 2
        mx = max(mx,ct)
    print(mx)
