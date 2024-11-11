import sys
input = lambda: sys.stdin.readline().rstrip()
N, M = map(int, input().split())
X = []
s = 0
for _ in range(N):
    b, l, u = map(int, input().split())
    t = M * u - (u - l) * b
    X.append((t, b, l, u))
    s += b * l

X = sorted(X, key = lambda x: -x[0])
A = [0] + [x[0] for x in X]
for i in range(1, N+1):
    A[i] += A[i-1]

def sum_excl(i, j):
    return A[j] if j <= i else A[j] - X[i][0]

def chk(i):
    t, bb, ll, uu = X[i]
    l, r = -1, N + 1
    while r - l > 1:
        m = (l + r) // 2
        if sum_excl(i, m) + t >= s:
            r = m
        else:
            l = m
    re = (r - (i < r)) * M
    rem = s - sum_excl(i, r)
    l, r = -1, M + 1
    while r - l > 1:
        m = (l + r) // 2
        if (m * uu - (uu - ll) * bb if m > bb else m * ll) >= rem:
            r = m
        else:
            l = m
    re += r
    return re

print(min(chk(i) for i in range(N)))