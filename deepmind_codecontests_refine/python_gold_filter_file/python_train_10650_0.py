import sys
from sys import stdout
import bisect as bi
import math
from collections import defaultdict as dd
from types import GeneratorType
##import queue 
##from heapq import heapify, heappush, heappop
##import itertools
##import io
##import os
##import operator
import random
##sys.setrecursionlimit(10**7)
input=sys.stdin.readline
##input = io.BytesIsoO(os.read(0, os.fstat(0).st_size)).readline
##fo=open("output2.txt","w")
##fi=open("input2.txt","w")
mo= 10**9+7
MOD=998244353
def cin():return map(int,sin().split())
def ain():return list(map(int,sin().split()))
def sin():return input().strip()
def inin():return int(input())

##----------------------------------------------------------------------------------------------------------------------




##for _ in range(inin()):
##    n=inin()
##    d=dd(int)
##    l=ain()
##    for i in l:
##        d[i]+=1
##    ke=list(d.keys())
##    ke.sort()
##    ans=ke[::]
##    for i in ke:
##        if(d[i]>1):
##            ans+=[i]*(d[i]-1)
##    
##    print(*ans)

##for _ in range(inin()):
##    n,m=cin()
##    l=ain()
##    d=dd(int)
##    for i in l:
##        d[i%m]+=1
##    ans=0
##    if(d[0]):ans+=1
##    for i in range(1,m//2+1):
##        if(d[i]>0):
##            if(m-i!=i):
##                if(d[m-i]):
##                    ans+=1
##                    mi=min(d[i],d[m-i])
##                    if(mi==d[i]):
##                        ans+=max(d[m-i]-mi-1,0)
##                    else:
##                        ans+=max(d[i]-mi-1,0)
##                else:
##                    ans+=d[i]
##            elif(m-i==i):
##                ans+=1
##        elif(d[m-i]):
##            ans+=d[m-i]
##    print(ans)

    
##for _ in range(inin()):
##    n,k=cin()
##    if(n%2):
##        print(n//2,n//2,1)
##    else:
##        if(n%4==0):
##            print(n//2,n//4,n//4)
##        else:
##            print(n//2-1,n//2-1,2)



def solve(n,k):
    if(n%2):
        return [n//2,n//2,1]
    else:
        if(n%4==0):
            return [n//2,n//4,n//4]
        else:
            return [n//2-1,n//2-1,2]
for _ in range(inin()):
    n,k=cin()
    ans=[]
    newn,newk=n-(k-3),3
    print(*(solve(newn,newk)+[1]*(k-3)))

            
            
            
    
                    
            
    
        
    
    
    
        
##-----------------------------------------------------------------------------------------------------------------------#
def msb(n):n|=n>>1;n|=n>>2;n|=n>>4;n|=n>>8;n|=n>>16;n|=n>>32;n|=n>>64;return n-(n>>1)
##2 ki power
def pref(a,n,f):
    pre=[0]*n
    if(f==0):         ##from beginning
        pre[0]=a[0]
        for i in range(1,n):
            pre[i]=a[i]+pre[i-1]
    else:              ##from end
        pre[-1]=a[-1]
        for i in range(n-2,-1,-1):
            pre[i]=pre[i+1]+a[i]
    return pre

# in given set of integers
def kadane(A):
    maxSoFar = maxEndingHere = start = end = beg = 0
    for i in range(len(A)):
        maxEndingHere = maxEndingHere + A[i]
        if maxEndingHere < 0:
            maxEndingHere = 0;beg = i + 1
        if maxSoFar < maxEndingHere:
            maxSoFar = maxEndingHere
            start = beg
            end = i
    return (maxSoFar,start,end)  #max subarray sum and its range 
def modFact(n, p):
    if(n<0):return 0
    if n >= p: return 0
    result = 1
    for i in range(1, n + 1):result = (result * i) % p
    return result
def ncr(n, r, p):
    if(n<r or n<0): return 0
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p ;den = (den * (i + 1)) % p 
    return (num * pow(den,p - 2, p)) % p


##https://github.com/cheran-senthil/PyRival/blob/master/pyrival/misc/bootstrap.py
##write @bootstrap before recursive func
def bootstrap(f, stack=[]):   
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
