# -*- coding: utf-8 -*-
from itertools import product
H, W = tuple(map(int, input().split()))

C = [tuple(map(int, input().split())) for _ in range(H)]
S = [[1]*W for _ in range(H)]
for h, w in product(range(H), range(W)):
    if C[h][w] == 1:
        S[h][w] = 0

for h, w in product(range(1, H), range(1, W)):
    if S[h][w]:
        S[h][w] = min(S[h-1][w-1], S[h-1][w], S[h][w-1]) + 1

result = 0
for sh in S:
    result = max(max(sh), result)

print(result**2)