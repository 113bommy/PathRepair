import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, M = mapint()
parents = [-1]*N
query = [[] for _ in range(N)]
get_into = [0]*N
for _ in range(N+M-1):
    a, b = mapint()
    parents[b-1] = a-1
    get_into[b-1] += 1
    query[a-1].append(b-1)

for i, c in enumerate(parents):
    if c==-1:
        root = i
        break

from collections import deque
Q = deque([root])
while Q:
    v = Q.popleft()
    for nx in query[v]:
        get_into[nx] -= 1
        if get_into[nx]==0:
            parents[nx] = v
            Q.append(nx)

for p in parents:
    print(p+1)