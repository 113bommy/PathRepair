'''
    Auther: ghoshashis545 Ashis Ghosh
    College: Jalpaiguri Govt Enggineering College

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
mod=1000000007
#mod=998244353
inf = float("inf")
vow=['a','e','i','o','u']
dx,dy=[-1,1,0,0],[0,0,1,-1]

def bo(i):
    return ord(i)-ord('0')

file = 1
def ceil(a,b):
    return (a+b-1)//b


def is_prime(n):
    if n < 2:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n%i==0:
            return False
    return True

def solve():

    
    for _ in range(1,ii()+1):
        n,m = mi()
        s = set()
        for i in range(n):
            s.add(i+1)
        for i in range(m):
            x = li()
            if x[1] in s:
                s.remove(x[1])
        s = list(s)
        for i in range(1,n+1):
            if i==s[0]:
                continue
            print(s[0],i)
        
        







            





    
        








        
if __name__ =="__main__":

    if(file):
    
       if path.exists('input.txt'):
           sys.stdin=open('input.txt', 'r')
           sys.stdout=open('output.txt','w')
       else:
           input=sys.stdin.readline
    solve()
