import sys
sys.setrecursionlimit(100000)

N = int(input())
d = {}
e = [[] for _ in range(N)]
dd = [-1]*N
for _ in range(N-1):
    u, v, w = list(map(int, input().split()))
    e[u-1].append(v-1)
    e[v-1].append(u-1)
    d[(u-1,v-1)]= d[(v-1,u-1)] = w

def dfs(i, _d):
    dd[i] = _d
    for c in e[i]:
        if dd[c]!=-1: continue
        dfs(c, _d+d[(i,c)])

dfs(0,0)
for _dd in dd:
    print(_dd%2)