# -*- coding: utf-8 -*-
"""
@author: zzf
@file: main.py
@time: 2018/11/13
"""
from collections import defaultdict

n = int(input())
a = list(map(int, input().split()))

m = defaultdict(int)

for i in range(n):
    m[a[i]] += 1

count = []
for k in m:
    count.append(m[k])
count.sort()

k = len(count)-1
ans = 0

if k == 0:
    print(count[k])
    exit(0)

for i in range(count[-1], 0, -1):
    tmp = i
    res = i
    pos = k
    while tmp %2 == 0 and pos > 0:
        tmp = tmp //2
        pos -= 1
        if count[pos] < tmp:
            break
        res += tmp
    ans = max(res, ans)

print(ans)



