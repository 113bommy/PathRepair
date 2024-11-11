import sys
import math
from pprint import pprint

n = int(input())
p = []
for _ in range(n):
    x, y = map(int, input().split())
    p.append((x, y))

s = {}
for i in range(n):
    x1, y1 = p[i]
    for j in range(i + 1, n):
        x2, y2 = p[j]
        slope = 0
        cons = 0
        if x1 == x2:
            slope = 10**10
            cons = x1
        else:
            slope = (y1 - y2) / (x1 - x2)
            cons = (y1 * x2 - x1 * y2) / (x2 - x1)
        if slope in s:
            if cons in s[slope]:
                s[slope][cons] += 1
            else:
                s[slope][cons] = 1
        else:
            s[slope] = {cons: 1}

p = []
for m in s:
    p.append(len(s[m]))
s = sum(p)
ans = 0
for x in p:
    ans += x * (s - x)
print(ans // 2)
