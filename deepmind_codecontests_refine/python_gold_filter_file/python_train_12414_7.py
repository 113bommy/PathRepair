from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key,lru_cache
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# import sys
# input = sys.stdin.readline

M = mod = 10**9 + 7 
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)

def li():return [int(i) for i in input().rstrip().split()]
def st():return str(input().rstrip())[2:-1]
def val():return int(input().rstrip())
def li2():return [str(i)[2:-1] for i in input().rstrip().split()]
def li3():return [int(i) for i in st()]


n,a,r,m = li()
l = sorted(li())


cnt1 = [0]
for i in l:cnt1.append(cnt1[-1] + i)
# cnt1 = cnt1[1:]

cnt2 = [0]
for i in l[::-1]:cnt2.append(cnt2[-1] + i)
# cnt2 = cnt2[1:]
cnt2 = cnt2[::-1]


def give(s):
    leftind = bl(l,s)
    rightind = br(l,s)
    a = leftind*s - cnt1[leftind]
    b = cnt2[rightind] - (len(l) - rightind)*s

    return [a,b]


def cost(s,b):
    temp = min(b,s)
    return temp*m + (b - temp)*r + (s - temp)*a



def binary():
    ans = float('inf')
    
    left = 0
    right = 10**18
    while left <= right:
        mid = (left + right) >> 1
        
        s1,b1 = give(mid)
        s2,b2 = give(mid + 1)

        if cost(s1,b1) < cost(s2,b2):
            ans = min(ans,cost(s1,b1))
            right = mid - 1
        else:
            ans = min(ans,cost(s2,b2))
            left = mid + 1
    return ans



m = min(m,a + r)


print(binary())