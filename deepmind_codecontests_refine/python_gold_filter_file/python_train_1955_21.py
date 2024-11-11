# -*- coding: utf-8 -*-
import sys 
from collections import Counter
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
cnt = Counter()

for i in range(N):
    cnt_2 = 0
    cnt_5 = 0
    a = float(readline())
    a = int(a * (10**9)+0.5)

    while a % 2 == 0:
        a //= 2
        cnt_2 += 1
    while a % 5 == 0:
        a //= 5
        cnt_5 += 1
    cnt[(cnt_2-9,cnt_5-9)] += 1
    
ans = 0
for (x1,y1),c1 in cnt.items():
    for (x2,y2),c2 in cnt.items():
        if x1+x2 >= 0 and y1+y2 >= 0:
            if x1 == x2 and y1 == y2:
                ans += c1*(c1-1)
            else:
                ans += c1*c2

print(ans//2)