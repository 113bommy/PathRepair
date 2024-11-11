from itertools import accumulate

N, K = map(int, input().split())
A = list(map(int, input().split()))

C = [0] + list(accumulate(A))
S = []

for i in range(N):
    for j in range(i + 1, N + 1):
        S.append(C[j] - C[i])

for i in range(64)[::-1]:
    tmp = []
    for s in S:
        if (s >> i) & 1:
            tmp.append(s)

    if len(tmp) >= K:
        S = tmp

res = 2**64 - 1

for i in range(K):
    res &= S[i]

print(res)