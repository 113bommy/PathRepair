# coding: utf-8
# Your code here!
from collections import deque
import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n,m = [int(i) for i in readline().split()]

if m%2: print(-1); exit()

#L = [0]*n

g = [[] for _ in range(n)]
for i in range(m):
    a,b = [int(i) for i in readline().split()]
    g[a-1].append((b-1,i))
    g[b-1].append((a-1,i))
#    L[a-1] += 1
#    L[b-1] += 1



used = [0]*m
usedp = [0]*n
def dfs(v):
    res = 0
    for (c,i) in g[v]:
        if used[i] == 1: continue
        used[i] = 1
        if usedp[c] == 1:
            res += 1
            print(v+1,c+1)
            continue
        usedp[c] = 1
        p =  dfs(c)
        if p%2 == 1:
            print(v+1,c+1)
        else:    
            print(c+1,v+1)
        res += p
    return res+1


for i in range(n):
    dfs(i)
#print(q)










