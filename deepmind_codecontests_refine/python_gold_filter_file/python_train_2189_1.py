import copy

INF = 10**10
v, e = map(int, input().split())
M = [[INF]*v for i in range(v)]
for i in range(v):
    M[i][i] = 0
for i in range(e):
    s, t, d = map(int, input().split())
    M[s][t] = d

# k:グラフの範囲
ans = copy.deepcopy(M)
for k in range(v):
    for i in range(v):
        if ans[i][k] == INF:
            continue
        for j in range(v):
            if ans[k][j] == INF:
                continue
            # i, jのグラフの最短距離
            ans[i][j] = min(ans[i][j], ans[i][k]+ans[k][j])

flag = False
for i in range(v):
    if ans[i][i] < 0:
        flag = True
        break
if flag:
    print('NEGATIVE CYCLE')
else:
    for line in ans:
        line = ['INF' if tmp == INF else tmp for tmp in line]
        print(*line)

