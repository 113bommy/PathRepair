# https://codeforces.com/problemset/problem/1338/A
from math import log2 as l, floor as f
for _ in range(int(input())):
    n = int(input())
    a = map(int, input().split())
    x = 0
    m = -1e100
    for i in a:
        m = max(m, i)
        x = max(x, m-i)
    if x == 0:
        print(0)
    else:
        print(f(l(x)+1))