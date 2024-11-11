from collections import Counter as count
from bisect import bisect
import sys
from math import ceil,gcd
from itertools import groupby
input = lambda: sys.stdin.readline().rstrip("\r\n")
for i in range(int(input())):
    n=int(input())
    ans=0
    i=1
    t=0
    while n>ans:
        ans+=i
        i+=2
        t+=1
    print(t)
    
        
