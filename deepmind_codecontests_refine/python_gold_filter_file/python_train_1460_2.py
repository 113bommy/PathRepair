# -*- coding: utf-8 -*-
'''
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_A&lang=jp
???????¨???????
?????§??£?????¢
'''

H, W = map(int, input().split())
C = list()
maxWidth = 0

for h in range(H):
    C.append(list(map(int, input().split())))

dp = dict()
for h in range(H+1):
    dp[(h, 0)] = 0

for w in range(W+1):
    dp[(0, w)] = 0

for h in range(1, H+1):
    for w in range(1, W+1):
        if C[h-1][w-1] == 1:
            dp[(h, w)] = 0
        else:
            dp[(h, w)] = min(dp[(h-1, w-1)], dp[(h-1, w)], dp[(h, w-1)]) + 1
            maxWidth = max(dp[(h, w)], maxWidth)

print(maxWidth**2)