import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log, ceil
from collections import defaultdict as dd
from collections import Counter as cc
from bisect import bisect_left as bl
from bisect import bisect_right as br

'''
testcase = sys.argv[1]
f = open(testcase, "r")
input = f.readline
'''

sys.setrecursionlimit(100000000)

intinp = lambda: int(input().strip())
stripinp = lambda: input().strip()
fltarr = lambda: list(map(float,input().strip().split()))
intarr = lambda: list(map(int,input().strip().split()))

ceildiv = lambda x,d: x//d if(x%d==0) else x//d+1

MOD=1_000_000_007

num_cases = intinp()
#num_cases = 1
#cases = []
for _ in range(num_cases):
    d, k = intarr()
    mi = int(d/((2**.5)*k))
    q = [mi*k, mi*k]
    ans = ['Ashish', 'Utkarsh']
    op = [[0,k], [k,0]]
    curr = 0

    while q[0]**2 + q[1]**2 <= d**2:
        curr ^= 1
        q[0] += op[curr][0]
        q[1] += op[curr][1]
    #print(q[0], q[1],d/(1.414) / k,q[0]**2 + q[1]**2 , d**2,d,k, q[0]//k, q[1]//k)
    print(ans[curr])
