from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline

from itertools import accumulate

M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]


for _ in range(val()):
    n = val()
    l = li()
    # print(l)
    cnt = Counter(l)
    l = sorted(cnt, key = lambda x:-cnt[x])

    if cnt[l[0]] == 2:
        print(len(cnt) - 1)
        continue
    l = deque(l)
    finans = 0
    # while len(l) > 1 and cnt[l[0]] == cnt[l[1]]:
    #     l.popleft()
    #     finans += 1
    l1 = []
    last = 0
    hell = 0
    temp = (10 ** 5) * cnt[l[0]]
    # print(l, temp)
    for i in l:
        curr = [last, hell]
        for j in range(cnt[i]):
            l1.append([last + hell, i])
            hell += 10 ** 5
            if cnt[i] == cnt[l[0]] and hell >= temp:
                hell = 0
                last += 1
            elif cnt[i] < cnt[l[0]] and hell >= temp - 10 ** 5:
                hell = 0
                last += 1
    # print(l1)
    l1.sort()
    l1 = [i[1] for i in l1]
    m = {}

    ans = float('inf')
    for i in range(len(l1)):
        if l1[i] in m:
            ans = min(ans, i - m[l1[i]] - 1)
        m[l1[i]] = i
    
    
    print(ans + finans)