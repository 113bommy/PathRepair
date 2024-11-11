'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineering College

'''
from os import path
from io import BytesIO, IOBase
import sys
from heapq import heappush,heappop
from functools import cmp_to_key as ctk
from collections import deque,Counter,defaultdict as dd 
from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right
from itertools import permutations
from datetime import datetime
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input().rstrip()
def mi():return map(int,input().split())
def li():return list(mi())
abc='abcdefghijklmnopqrstuvwxyz'
# mod=1000000007
mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def bo(i):
    return ord(i)-ord('0')

file = 1
def ceil(a,b):
    return (a+b-1)//b

# write fastio for getting fastio template.
    



def solve():


    # for _ in range(ii()):
        
    n = ii()
    a = li()
    m = ii()
    b = li()
    if sum(a) != sum(b):
        print('-1')
        return
    s1,s2 = 0,0
    i,j,ans = 0,0,0
    while i < n and j < m:
        if (s1+a[i])<=(s2+b[j]):
            s1 += a[i]
            i+=1
        else:
            s2 += b[j]
            j+=1
        if s1==s2:
            ans+=1
            s1,s2=0,0
    if i < n:
        ans+=1
    if  j < m:
        ans+=1
    print(ans)









            





    
        








        
if __name__ =="__main__":

    if(file):

        if path.exists('input.txt'):
            sys.stdin=open('input.txt', 'r')
            sys.stdout=open('output.txt','w')
        else:
            input=sys.stdin.readline
    solve()
