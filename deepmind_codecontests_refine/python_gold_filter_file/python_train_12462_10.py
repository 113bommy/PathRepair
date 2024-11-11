S = [str(input()) for i in range(2)]
S[0] = S[0].replace('X','1')
S[1] = S[1].replace('X','1')

n = len(S[0])
if n == 1:
    print(0)
    exit()

INF = 10**18
from collections import defaultdict
dp = defaultdict(lambda: -INF)
for i in range(0, 2):
    for j in range(0, 2):
        dp[(i, j)] = -INF
dp[(int(S[0][0]), int(S[1][0]))] = 0

for i in range(1, n):
    nx = defaultdict(lambda: -INF)
    for j in range(0, 2):
        for k in range(0, 2):
            nx[(int(S[0][i]), int(S[1][i]))] = max(nx[(int(S[0][i]), int(S[1][i]))], dp[(j, k)])
    for j in range(0, 2):
        for k in range(0, 2):
            if dp[(j, k)] == -INF:
                continue
            if j == 0 and k == 0:
                if S[0][i] == '1' and S[1][i] != '1':
                    nx[(1, 1)] = max(nx[(1, 1)], dp[(j, k)]+1)
                if S[0][i] != '1' and S[1][i] == '1':
                    nx[(1, 1)] = max(nx[(1, 1)], dp[(j, k)]+1)
                if S[0][i] != '1' and S[1][i] != '1':
                    nx[(1, 0)] = max(nx[(1, 0)], dp[(j, k)]+1)
                    nx[(0, 1)] = max(nx[(0, 1)], dp[(j, k)]+1)
                    nx[(1, 1)] = max(nx[(1, 1)], dp[(j, k)]+1)
            if j == 0 and k == 1:
                if S[0][i] != '1' and S[1][i] != '1':
                    nx[(1, 1)] = max(nx[(1, 1)], dp[(j, k)]+1)
            if j == 1 and k == 0:
                if S[0][i] != '1' and S[1][i] != '1':
                    nx[(1, 1)] = max(nx[(1, 1)], dp[(j, k)]+1)
    dp = nx
ans = -INF
for k, v in dp.items():
    ans = max(ans, v)
print(ans)
