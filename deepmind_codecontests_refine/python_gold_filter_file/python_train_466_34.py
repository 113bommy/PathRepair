from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left

max_point = [i for i in range(500, 3000, 500)]
time = map(int, input().split())
wrongs = map(int, input().split())

suc, un = map(int, input().split())
ans = 0

for mx, t, w in zip(max_point, time, wrongs):
    ans += max(0.3*mx, (1-t/250)*mx - 50*w)

ans += suc*100
ans -= un*50

print(int(ans))






