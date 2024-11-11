import sys
sys.setrecursionlimit(500000)
 
N = int(input())
ABC = [list(map(int, input().split())) for i in range(N-1)]
Q, K = map(int, input().split())
D = [0] * (N+1)
L = [[] for i in range(N+1)]
for a, b, c in ABC:
    L[a].append([b, c])
    L[b].append([a, c])
 
 
def dfs(n, np):
    for nc in L[n]:
        if nc[0] == np:
            continue
        else:
            D[nc[0]] = D[n] + nc[1]
            dfs(nc[0], n)
 
 
dfs(K, 0)
for i in range(Q):
    x, y = map(int, input().split())
    print(D[x] + D[y])
