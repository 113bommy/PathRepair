from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline

# M = mod = 998244353
def factors(n):return sorted(list(set(reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]


n = val()
l = li()
l1 = l[:]
l2 = l[:]

i = 0
l1 = sorted(list(set(l1)))
doit = tot1 = 0
cn = Counter(l1)
l = l1[:]
while i < len(l1):
    if cn[l[i] - 1] > 0:
        cn[l[i]] -= 1
        cn[l[i] - 1] += 1
        l[i] -= 1
        i += 1
    else:
        cn[l[i]] -= 1
        cn[l[i] + 1] += 1
        l[i] += 1
        if i<len(l1) - 1 and l[i + 1] == l[i]:i += 2
        else:i += 1
# print(cn)
tot1 = sum(1 for i in cn if cn[i])









# print(l1)



i = 0

cnt = Counter(l2)
l2 = sorted(l2)

l = l2[:]



for i in range(n):
    if cnt[l[i] - 1] == 0:
        cnt[l[i] - 1] += 1
        cnt[l[i]] -= 1
        l[i] -= 1
    elif cnt[l[i]] > 1:
        cnt[l[i] + 1] += 1
        cnt[l[i]] -= 1
        l[i] += 1


tot2 = sum(1 for i in cnt if cnt[i])





print(tot1,tot2)