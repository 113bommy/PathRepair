import sys
sys.setrecursionlimit(10**9)

n = int(input())

from collections import defaultdict
d = defaultdict(list)

for _ in range(n-1):
    a,b,c = map(int,input().split())
    d[a-1].append((b-1, c))
    d[b-1].append((a-1, c))

q,k = map(int,input().split())

global dist
dist = [-1 for _ in range(n)]
def dfs(l, pos):
    dist[pos] = l
    for to, c in d[pos]:
        if dist[to] == -1:
            dfs(l+c,to)

dfs(0, k-1)

for _ in range(q):
    x,y = map(int,input().split())
    print(dist[x-1] + dist[y-1])
