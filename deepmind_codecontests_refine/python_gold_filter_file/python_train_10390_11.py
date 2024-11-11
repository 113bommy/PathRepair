import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, K = mapint()
As = list(mapint())
double_As = As*2
idx_dic = {}
idx_lis = [N+1]*(2*N)
for i in range(N*2-1, -1, -1):
    a = double_As[i]
    if a in idx_dic:
        idx_lis[i] = idx_dic[a]+1
    idx_dic[a] = i
doubling = [[0]*N for _ in range(60)]
accum = [[0]*N for _ in range(60)]
doubling[0] = [i%N for i in idx_lis[:N]]
accum[0] = [a-i for i, a in enumerate(idx_lis[:N])]
for i in range(1, 60):
    for j in range(N):
        doubling[i][j] = doubling[i-1][doubling[i-1][j]]
        accum[i][j] = accum[i-1][j] + accum[i-1][doubling[i-1][j]]
now = 0
cum = 0
cnt = 0
for i in range(59, -1, -1):
    if cum + accum[i][now]>N*K:
        continue
    else:
        cum += accum[i][now]
        now = doubling[i][now]
ans = []
while cum<N*K:
    if cum+accum[0][now]<=N*K:
        cum += accum[0][now]
        now = doubling[0][now]
    else:
        ans.append(As[now])
        now += 1
        cum += 1
print(*ans)
