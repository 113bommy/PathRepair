
import os
import sys
from io import BytesIO, IOBase

from collections import defaultdict, Counter

input = lambda: sys.stdin.readline().rstrip("\r\n")
import math

def I():
    return(int(input()))
def lint():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().split()))
# Python program to print all
# primes smaller than or equal to
# n using Sieve of Eratosthenes

import heapq

def ask(a,b,c):
    print(f"? {a} {b} {c}")
    sys.stdout.flush()
    res=int(input())
    sys.stdout.flush()
    return res
t=I()

for _ in range(t):
    n = I()
    l = lint()
    m=max(l)
    arr = list(set(x % 3 for x in l))
    
    if m%3==0:
        if 1 in arr or 2 in arr:
            print(m//3+1)
        else:
            print(m//3)
    elif m%3==1:
        tmp=m//3
        if 2 in arr:
            tmp+=1
        if 1 in l or m-1 in l:
            tmp+=1
        
        print(max(m//3+1,tmp))
    else:
        if 1 in arr:
            
            print(m//3+2)
        else:
            
            print(m//3+1)

            

   


        


    