#	✪ H4WK3yE乡
#	Mayank Chaudhary
#                  I can :)
#	ABES EC , Ghaziabad
# ///==========Libraries, Constants and Functions=============///
import sys
from bisect import bisect_left,bisect_right,insort
from collections import deque,Counter
from math import gcd,sqrt,factorial,ceil,log10
from itertools import permutations
from heapq import heappush,heappop,heapify
inf = float("inf")
mod = 1000000007
mini=1000000007

def max_subarray(array):                                                # <------- Extended Kadane's algo which gives maximum sum sub-array but also the starting and ending indexes
    max_so_far = max_ending_here = array[0]
    start_index = 0
    end_index = 0
    for i in range(1, len(array) -1):
        temp_start_index = temp_end_index = None
        if array[i] > (max_ending_here + array[i]):
            temp_start_index = temp_end_index = i
            max_ending_here = array[i]
        else:
            temp_end_index = i
            max_ending_here = max_ending_here + array[i]
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
            if temp_start_index != None:
                start_index = temp_start_index
            end_index = i
    print(max_so_far, start_index, end_index)


def ncr(n,r):                                                          # < ------ To calculate nCr mod p value using Fermat Little under modulo m
    d=10**9+7
    num=fact(n)
    den=(fact(r)*fact(n-r))%d
    den=pow(den,d-2,d)
    return (num*den)%d

def sieve(n):                                                          # <----- sieve of eratosthenes for prime no.
    prime=[True for i in range(n+1)]
    lst=[]
    p=2
    while p*p<=n:
        if prime[p]:
            for i in range(p*p,n+1,p):
                prime[i]=False
        p=p+1
    for i in range(2,n+1):
        if prime[i]:
            lst.append(i)
    return lst
    
        
def binary(number):                                             #  <----- calculate the no. of 1's in binary representation of number
    result=0
    while number:
        result=result+1
        number=number&(number-1)
    return result

def calculate_factors(n):                                #<---- most efficient method to calculate no. of factors of number             
    hh = [1] * (n + 1); 
    p = 2; 
    while((p * p) < n): 
        if (hh[p] == 1): 
            for i in range((p * 2), n, p): 
                hh[i] = 0; 
        p += 1;  
    total = 1; 
    for p in range(2, n + 1): 
        if (hh[p] == 1):  
            count = 0; 
            if (n % p == 0): 
                while (n % p == 0): 
                    n = int(n / p); 
                    count += 1; 
                total *= (count + 1); 
    return total;

def prime_factors(n):                                         #<------------ to find prime factors of a no.
    i = 2
    factors = set()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            factors.add(n//i)
            n=n//i
            factors.add(i)
        
    if n > 1:
        factors.add(n)
    return (factors)

def isPrime(n):                                                      #<-----------check whether a no. is prime or not
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    for i in range(3,int(n**0.5)+1,2):   # only odd numbers
        if n%i==0:
            return False    

    return True
def solve(n):
    if n==1:
        return (1)
    p=2;result=[]
    while (p*p)<=n:
        if n%p==0:
            result.append(p);result.append(n//p)
        p=p+1
    return result

def atMostSum(arr, n, k): 
    _sum = 0
    cnt = 0
    maxcnt = 0
      
    for i in range(n): 
  
        # If adding current element doesn't 
        # Cross limit add it to current window 
        if ((_sum + arr[i]) <= k): 
            _sum += arr[i] 
            cnt += 1
          
        # Else, remove first element of current 
        # window and add the current element 
        elif(sum != 0): 
            _sum = _sum - arr[i - cnt] + arr[i] 
          
        # keep track of max length. 
        maxcnt = max(cnt, maxcnt) 
  
    return maxcnt 
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
# ///==========MAIN=============///
n,c=get_ints()
count=1
Arr=get_array()
for i in range(1,n):
    if Arr[i]-Arr[i-1]<=c:
        count+=1
    else:
        count=1
print(count)
