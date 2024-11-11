N, U, V = map(int, input().split())
A = [[] for _ in range(N)]
import sys
sys.setrecursionlimit(10**8)
for _ in range(N - 1):
    a, b = map(int, input().split())

    A[a - 1].append(b - 1)
    A[b - 1].append(a - 1)

C = [0] * N
D = [0] * N

def DFS(x, pre, cnt, C):
    C[x] = cnt
    cnt += 1
    for a in A[x]:
        if a == pre:
            continue

        DFS(a, x, cnt, C)


DFS(V - 1, -1, 0, C)
DFS(U - 1, -1, 0, D)
ans=0
for i in range(N):
    if C[i]>D[i]:
        ans =max(ans, C[i]-1)
print(ans)
