from bisect import bisect_right
from math import log

N = int(input())
X = list(map(int, input().split()))
L = int(input())

R = [[-1] * N for i in range(int(log(N, 2) + 1))]
# 1日で行けるところをにぶたんで求める
for i in range(N):
    R[0][i] = bisect_right(X, X[i] + L) - 1

# ダブリング
for k in range(1, len(R)):
    for i in range(N):
        R[k][i] = R[k-1][R[k-1][i]]

# にぶたんでクエリに答えていく
Q = int(input())
for q in range(Q):
    a, b = map(int, input().split())
    a, b = min(a, b)-1, max(a, b)-1

    ans = 0
    for k in range(len(R))[::-1]:
        if R[k][a] < b:
            a = R[k][a]
            ans += 2 ** k
    print(ans + 1)
