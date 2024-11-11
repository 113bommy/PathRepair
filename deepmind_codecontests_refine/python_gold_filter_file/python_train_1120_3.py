p = 998244353
n, k = map(int, input().split())
LRs = [tuple(map(int, input().split())) for _ in range(k)]
A = [0] * (2 * n + 1)
for lj, rj in LRs:
    A[lj] += 1
    A[rj + 1] -= 1
s = 0
for i in range(1, n):
    s = (s + A[i]) % p
    for lj, rj in LRs:
        A[i + lj] += s
        A[i + rj + 1] -= s
print(s)
