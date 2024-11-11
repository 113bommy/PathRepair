# -*- coding: utf-8 -*-
from itertools import combinations
def inpl(): return map(int, input().split())

N = int(input())
S = [list(input()) for _ in range(N)]
ans = 0

for k in range(N):
    for i, j in combinations(range(N), 2):
        if S[i][(j+k)%N] != S[j][(i+k)%N]:
            break
    else:
        ans += N

print(ans)
