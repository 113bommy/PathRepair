import sys
sys.setrecursionlimit(1000000)
 
N = int(input())
X = [[] for _ in range(N)]
for _ in range(N-1):
    u, v, w = map(int, input().split())
    X[u-1].append((v-1, w%2))
    X[v-1].append((u-1, w%2))
 

D = [-1] * N
def calc(i, c):
    D[i] = c
    for j, w in X[i]:
        if D[j] < 0:
            calc(j, D[i]^w)
 
calc(0, 0)
for d in D:
    print(d)