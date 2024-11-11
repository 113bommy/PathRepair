import bisect
import decimal
from decimal import Decimal
import os
from collections import Counter
import bisect
from collections import defaultdict
import math 
import random
import heapq 
from math import sqrt,log2,floor
import sys
from functools import reduce, cmp_to_key
from collections import deque
import threading
from itertools import combinations
from io import BytesIO, IOBase
from itertools import accumulate

# sys.setrecursionlimit(200000)
# mod = 10**9+7
# mod = 998244353
decimal.getcontext().prec = 46

def primeFactors(n): 
    prime = set()
    while n % 2 == 0: 
        prime.add(2)
        n = n//2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            prime.add(i)
            n = n//i 
    if n > 2: 
        prime.add(n)
    return list(prime)
    
def getFactors(n) : 
    factors = []
    i = 1
    while i <= math.sqrt(n): 
        if (n % i == 0) : 
            if (n // i == i) : 
                factors.append(i)
            else : 
                factors.append(i)
                factors.append(n//i)
        i = i + 1
    return factors
    
def modefiedSieve(): 
    mx=10**7+1
    sieve=[-1]*mx
    for i in range(2,mx):
        if sieve[i]==-1:
            sieve[i]=i
            for j in range(i*i,mx,i):
                if sieve[j]==-1:
                    sieve[j]=i
    return sieve
    
def SieveOfEratosthenes(n): 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    num = []
    for p in range(2, n+1): 
        if prime[p]: 
            num.append(p)
    return num

def lcm(a,b):
    return (a*b)//math.gcd(a,b)

def sort_dict(key_value):
    return sorted(key_value.items(), key = lambda kv:(kv[1], kv[0]))

def list_input():
    return list(map(int,input().split()))
    
def num_input():
    return map(int,input().split())
    
def string_list():
    return list(input())
    
def decimalToBinary(n):  
    return bin(n).replace("0b", "")  
    
def binaryToDecimal(n): 
    return int(n,2) 
    
def DFS(n,s,adj):              
    visited = [False for i in range(n+1)]  
    stack = [] 
    stack.append(s)  
  
    while (len(stack)):  
        s = stack[-1]  
        stack.pop() 
  
        if (not visited[s]):  
            visited[s] = True 
            
        for node in adj[s]:  
            if (not visited[node]):  
                stack.append(node)  
        
def maxSubArraySum(a,size): 
    maxint = 10**10
    max_so_far = -maxint - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
  
        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 
        
def countSetBits(n): 
    count = 0
    while (n): 
        n &= (n-1)  
        count+= 1
      
    return count 
        
def solve():
    n = int(input())
    temp = sorted(list_input())
    arr = [temp[-1]]
    for i in range(n-1):
        arr.append(temp[i])
    prev = n-1
    for i in range(n):
        forwrd = (i+1)%n
        if arr[i] >= arr[forwrd]+arr[prev]:
            indx = forwrd
            forwrd = (forwrd+1)%n
            while forwrd != prev:
                if arr[i] < arr[forwrd]+arr[prev]:
                    arr[indx],arr[forwrd] = arr[forwrd],arr[indx]
                    break
                forwrd = (forwrd+1)%n
            if forwrd == prev:
                print('NO')
                return
        prev = (prev+1)%n
    print('YES')
    print(*arr)
    
t = 1
#t = int(input())
for _ in range(t):
    solve()


    
    
    
    
