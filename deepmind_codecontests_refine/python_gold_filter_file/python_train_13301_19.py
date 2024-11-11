#!/usr/bin python3
# -*- coding: utf-8 -*-

r, c, k = map(int, input().split())
itm = [[0]*(c) for _ in range(r)]
for i in range(k):
    ri, ci, vi = map(int, input().split())
    itm[ri-1][ci-1] = vi

dp0 = [[0]*4 for c_ in range(3005)]
dp1 = [[0]*4 for c_ in range(3005)]

for i in range(r):
    for j in range(c):
        nowv = itm[i][j]
        dp0[j][3] = max(dp0[j][3], dp0[j][2] + nowv)
        dp0[j][2] = max(dp0[j][2], dp0[j][1] + nowv)
        dp0[j][1] = max(dp0[j][1], dp0[j][0] + nowv)

        dp0[j+1][0] = max(dp0[j+1][0], dp0[j][0])
        dp0[j+1][1] = max(dp0[j+1][1], dp0[j][1])
        dp0[j+1][2] = max(dp0[j+1][2], dp0[j][2])
        dp0[j+1][3] = max(dp0[j+1][3], dp0[j][3])

        dp1[j][0] = max(dp1[j][0], max(dp0[j]))
    dp0 = dp1.copy()

print(max(dp1[c-1]))
