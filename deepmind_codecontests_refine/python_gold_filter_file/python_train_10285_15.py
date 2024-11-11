# Surrounded Nodes
from collections import deque
import sys
sys.setrecursionlimit(10**8)
mod = 10**9 + 7
N = int(input())
G = [[] for i in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)
S = -1
for i in range(1, N+1):
    if len(G[i]) == 1:
        S = i
        break
visited = [False for i in range(N+1)]
parent = [-1 for i in range(N+1)]
count = [1 for i in range(N+1)]

ans = N*pow(2, N-1, mod)
stack = deque()


def dfs(node):
    visited[node] = True
    for child in G[node]:
        if visited[child] == False:
            parent[child] = node
            stack.append((node, child))
            dfs(child)


powers = [1 for i in range(2*10**5+1)]
for i in range(1, 2*10**5+1):
    powers[i] = powers[i-1]*2 % mod

dfs(S)
while stack:
    mom, child = stack.pop()
    count[mom] += count[child]
ans = 0
for i in range(1, N+1):
    if len(G[i]) > 1:
        ans += powers[N-1]
        for x in G[i]:
            if x != parent[i]:
                ans -= powers[count[x]]
        ans -= powers[N-count[i]]
        ans += len(G[i]) - 1
        ans %= mod
D = pow(2, N, mod)
print(ans*pow(D, mod-2, mod) % mod)