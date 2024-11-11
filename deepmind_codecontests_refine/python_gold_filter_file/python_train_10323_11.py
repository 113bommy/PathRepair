from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
 
# M = mod = 998244353
# def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
# def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]


n = val()
l = li()

freq = [0 for i in range(10**5 + 5)]
ans = 0
cnt = Counter()
for ind,i in enumerate(l):
    if not freq[i]:
        freq[i] += 1
        cnt[freq[i]] += 1
    else:
        cnt[freq[i]] -= 1
        if not cnt[freq[i]]:cnt.pop(freq[i])
        freq[i] += 1
        cnt[freq[i]] += 1
    
    if len(cnt) == 1:
        for j in cnt:
            if cnt[j] == 1:
                ans = ind + 1
            elif cnt[j] > 1 and j == 1:
                ans = ind + 1
        
    elif len(cnt) == 2:
        # print('ind : ',ind,cnt)
        first = second = -1
        for j in cnt:
            if first == -1:first = j
            else:second = j
        if (first == cnt[first] == 1) or (second == cnt[second] == 1) or (cnt[first] == 1 and first == second + 1) or (cnt[second] == 1 and second == first + 1):
            ans = ind + 1
print(ans)