import sys
sys.setrecursionlimit(10**9)

INF = 10**15

N = int(input())
As = list(map(int, input().split()))
adjL = [[] for _ in range(N)]
for _ in range(N-1):
    U, V = map(int, input().split())
    U, V = U-1, V-1
    adjL[U].append(V)
    adjL[V].append(U)

useds = [False] * N
sizes = [0] * N
dp0 = [[] for _ in range(N)]
dp1 = [[] for _ in range(N)]

def dfs(v):
    useds[v] = True
    sizes[v] = 1
    dp0[v] = [As[v] if As[v] > 0 else INF]
    dp1[v] = [As[v] if As[v] < 0 else INF]
    for v2 in adjL[v]:
        if useds[v2]: continue
        dfs(v2)
        merged0 = [INF] * (sizes[v]+sizes[v2])
        merged1 = [INF] * (sizes[v]+sizes[v2])
        for i in range(sizes[v]):
            for j in range(sizes[v2]):
                merged0[i+j] = min(merged0[i+j], dp0[v][i]+dp0[v2][j])
                merged1[i+j] = min(merged1[i+j], dp0[v][i]+dp1[v2][j])
                merged1[i+j] = min(merged1[i+j], dp1[v][i]+dp0[v2][j])
                merged1[i+j] = min(merged1[i+j], dp1[v][i]+dp1[v2][j])
                if dp0[v2][j] != INF:
                    merged0[i+j+1] = min(merged0[i+j+1], dp0[v][i])
                if dp1[v2][j] < 0:
                    merged0[i+j+1] = min(merged0[i+j+1], dp0[v][i])
                if dp0[v2][j] != INF:
                    merged1[i+j+1] = min(merged1[i+j+1], dp1[v][i])
                if dp1[v2][j] < 0:
                    merged1[i+j+1] = min(merged1[i+j+1], dp1[v][i])
        sizes[v] += sizes[v2]
        dp0[v] = merged0
        dp1[v] = merged1

dfs(0)

for i, (v0, v1) in enumerate(zip(dp0[0], dp1[0])):
    if v0 != INF or v1 < 0:
        print(i)
        break
