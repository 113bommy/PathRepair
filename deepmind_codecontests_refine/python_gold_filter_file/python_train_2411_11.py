import sys
import math
from pprint import pprint

n = int(input())
p = [list(map(int, input().split())) for i in range(n)]
p.sort()
s = {}
for i in range(n):
    x1, y1 = p[i]
    for j in range(i + 1, n):
        x2, y2 = p[j]
        slope = 0
        cons = 0
        if x1 - x2 == 0:
            slope = sys.maxsize
            cons = x1
        else:
            slope = (y2 - y1) / (x2 - x1)
            cons = (y1 * x2 - x1 * y2) / (x2 - x1)
        if slope in s:
            if cons in s[slope]:
                s[slope][cons] += 1
            else:
                s[slope][cons] = 1
        else:
            s[slope] = {cons: 1}
ans = 0
cnt = 0

for x in s:
    ans += cnt * len(s[x])
    cnt += len(s[x])
print(ans)
