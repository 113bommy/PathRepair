# -*- coding: utf-8 -*-
h,w = map(int, input().split())

c = []
for _ in range(10):
    line = list(map(int, input().split()))
    c.append(line)

for k in range(10):
    for i in range(10):
        for j in range(10):
            c[i][j] = min(c[i][j], c[i][k]+c[k][j])

ret = 0
for _ in range(h):
    for a in map(int, input().split()):
        if a>=0:
            ret += c[a][1]

print(ret)
