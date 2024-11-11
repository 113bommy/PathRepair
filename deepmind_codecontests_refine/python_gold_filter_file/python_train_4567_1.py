import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5+100)
from collections import *

def dfs(v, pv, de):
    for nv in G[v]:
        if nv==pv:
            continue
        
        dfs(nv, v, de+1)
        left[v] = max(left[v], left[nv]-1)
        right[v] = min(right[v], right[nv]+1)
    
    if v in d:
        if d[v]<left[v] or right[v]<d[v] or (d[v]-d[root])%2!=de%2:
            print('No')
            exit()
        else:
            left[v] = d[v]
            right[v] = d[v]
    
def dfs2(v, pv, now):
    ans[v] = now
    
    for nv in G[v]:
        if nv==pv:
            continue
        
        if left[nv]<=now-1<=right[nv]:
            dfs2(nv, v, now-1)
        elif left[nv]<=now+1<=right[nv]:
            dfs2(nv, v, now+1)
        else:
            print('No')
            exit()
    
N = int(input())
G = [[] for _ in range(N)]

for _ in range(N-1):
    A, B = map(int, input().split())
    G[A-1].append(B-1)
    G[B-1].append(A-1)

d = defaultdict(int)
K = int(input())

for _ in range(K):
    V, P = map(int, input().split())
    d[V-1] = P
    root = V-1

left = [-10**18]*N
right = [10**18]*N
dfs(root, -1, 0)
ans = [-1]*N
dfs2(root, -1, d[root])
print('Yes')

for ans_i in ans:
    print(ans_i)
