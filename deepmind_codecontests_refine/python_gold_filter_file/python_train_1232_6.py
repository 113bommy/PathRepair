import sys
sys.setrecursionlimit(10**6)
def dfs(v,p,d):
    for i, j in tree[v]:
        if i != p:
            depth[i] = d + j
            dfs(i,v,d+j)

N = int(input())

tree = [[] for _ in range(N)]

for i in range(N-1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append((b,c))
    tree[b].append((a,c))

Q, K = map(int, input().split())

depth = [0 for i in range(N)]
depth[K-1] = 0

dfs(K-1,-1,0)

for _ in range(Q):
    x, y = map(int, input().split())
    print(depth[x-1] + depth[y-1])