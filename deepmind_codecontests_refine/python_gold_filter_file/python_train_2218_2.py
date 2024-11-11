import sys
input = sys.stdin.readline
import math
import copy

n = int(input())
p = list(map(int,input().split()))
up = []
down = []
i = 0
if p[1] > p[0]:
    None
else:
    while p[i+1] < p[i]:
        i += 1
        if i == n-1:
            exit(print(0))

up_num = 0
down_num = 0
for j in range(n-1-i):
    if p[j+i+1] > p[j+i]:
        if down_num != 0:
            down.append(down_num)
            down_num = 0
        up_num += 1
    else:
        if up_num != 0:
            up.append(up_num)
            up_num = 0
        down_num += 1
if down_num != 0:
    down.append(down_num)
if len(up) == 0 or len(down) == 0:
    exit(print(0))
lim = max(max(up),max(down), up_num,i)
if i == lim or up_num == lim:
    exit(print(0))
ans = 0
for j in range(len(up)):
    if (max(up[j],down[j]) == lim) and up[j] == down[j] and lim % 2 ==0:
        ans += 1
if ans >= 2:
    ans = 0
print(ans)