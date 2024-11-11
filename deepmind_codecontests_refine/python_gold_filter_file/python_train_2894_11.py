# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

N, Q = map(int, input().split())
ab = [None] * (N - 1)
for i in range(N - 1):
    ab[i] = list(map(int, input().split()))
ab = sorted(ab, key=lambda x: (x[0], x[1]))

px_n = [0] * N
for i in range(Q):
    p, x = list(map(int, input().split()))
    px_n[p-1] += x

ans = [0] * N
ans[0] = px_n[0]
for (a, b) in ab:
    ans[b-1] += ans[a-1] + px_n[b-1]

print(*ans)
