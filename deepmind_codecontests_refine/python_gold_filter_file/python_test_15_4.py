import sys
input = lambda: sys.stdin.readline().rstrip()
import bisect
import itertools
from collections import deque

def findtick(a, n, m, k, i, j, used):
    if a[i][j] != '*':
        return -1
    for d in range(0, 100):
        if 0 <= i - d < n and 0 <= j - d < m:
            if a[i - d][j - d] == '*':
                continue
            else:
                break
        else:
            break
    msize = d

    
    for d in range(0, 100):
        if 0 <= i - d < n and 0 <= j + d < m:
            if a[i - d][j + d] == '*':
                continue
            else:
                break
        else:
            break
    psize = d
    x = min(msize, psize)
    if x - 1 >= k:
        for d in range(x):
            used[i - d][j - d] = True
            used[i - d][j + d] = True
        return x - 1
    else:
        return -1



    
def solve():
    n, m, k = map(int,input().split())
    a = [list(input()) for _ in range(n)]
    used = [[False] * m for _ in range(n)]
    ans = []
    for i in range(n):
        for j in range(m):
            x = findtick(a, n, m, k, i, j, used)
            if x > 0:
                ans.append(x)
    for i in range(n):
        for j in range(m):
            if used[i][j] == False and a[i][j] == '*':
                print('No')
                return
    print("Yes")










t = int(input())
for _ in range(t):
    solve()

