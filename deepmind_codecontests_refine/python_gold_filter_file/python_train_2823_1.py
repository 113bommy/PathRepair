from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left

nums = ["6", "7", "8", "9", "T", "J", "Q", "K", "A"]

cards = {n:i for i, n in enumerate(nums)}

s = input()
c1, c2 = input().split()
ok = False
if s in c1 and s not in c2:
    ok = True
elif s not in c1 and s not in c2:
    if c1[-1] == c2[-1] and cards[c1[0]] > cards[c2[0]]:
        ok = True
elif s in c1 and s in c2:
    if c1[-1] == c2[-1] and cards[c1[0]] > cards[c2[0]]:
        ok = True

if ok:
    print("YES")
else:
    print("NO")

