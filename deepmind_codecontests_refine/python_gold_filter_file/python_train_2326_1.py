from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left

d = int(input())
n = int(input())
arr = list(map(int, input().split()))
arr.pop(-1)
arr = [i for i in arr if i != d]

if len(arr) < 1:
    print(0)
else:
    # arr.pop(0)
    ans = 0
    for num in arr:
        ans += d- num

    print(ans)