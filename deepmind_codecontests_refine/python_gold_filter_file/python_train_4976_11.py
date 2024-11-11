import sys
input = sys.stdin.readline

#input
N, M = map(int, input().split())
u = [[] for i in range(N)]
#（便宜的に地点から-1としておく）
for i in range(M):
    s, t = map(int, input().split())
    u[s-1].append(t-1)

#output
#地点vにたどり着く確率をp[v]とする。
p = [0] * N
p[0] = 1
for v in range(N):
    for i in range(v):
        if v in u[i]:
            p[v] += p[i]/len(u[i])

#期待値をゴールから逆順に求めていく。点vからゴールまでの移動距離の期待値をq[v]とする。
q = [0] * N
q[N-1] = 0
for v in reversed(range(N)):
    for i in u[v]:
        q[v] += (1 + q[i])/len(u[v])

v = [0] * N
for i in range(N-1):
    a = len(u[i])
    if a > 1:
        b = max(q[c] for c in u[i])
        v[i] = p[i]*(q[i] - (1+b))/(a-1)

print(q[0]+min(v))
