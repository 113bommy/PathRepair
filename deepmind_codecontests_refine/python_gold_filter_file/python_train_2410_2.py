#!/usr/bin/env python3

n = int(input())

p= n*[-1]
c= n*[1]

for i in range(n):
    p[i],c[i] = map(int, input().split())
    p[i] -= 1

cc = c[:]
for i in range(n):
    if p[i] >= 0:
        cc[p[i]] = cc[p[i]] * c[i]

answer = ""
for i,x in enumerate(cc):
    if x:
        answer += f"{i+1} "
if answer:
    print(answer)
else:
    print(-1)

