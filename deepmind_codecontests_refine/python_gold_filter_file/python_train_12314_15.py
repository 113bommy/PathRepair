##############--->>>>> Deepcoder Amit Kumar Bhuyan <<<<<---##############

"""
 Perfection is achieved not when there is nothing more to add, but rather when there is nothing more to take away.
"""
from __future__ import division, print_function
 
import os,sys
from io import BytesIO, IOBase
 
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
 
 
def ii():  return int(input())
def si():  return input()
def mi():  return map(int,input().strip().split(" "))
def msi(): return map(str,input().strip().split(" "))
def li():  return list(mi())
 
def dmain():
    sys.setrecursionlimit(1000000)
    threading.stack_size(1024000)
    thread = threading.Thread(target=main)
    thread.start()
    
#from collections import deque, Counter, OrderedDict,defaultdict
#from heapq import nsmallest, nlargest, heapify,heappop ,heappush, heapreplace
#from math import log,sqrt,factorial,cos,tan,sin,radians
#from bisect import bisect,bisect_left,bisect_right,insort,insort_left,insort_right
#from decimal import *
#import threading
#from itertools import permutations
#Copy 2D list  m = [x[:] for x in mark] .. Avoid Using Deepcopy
import sys
input = sys.stdin.readline
scanner = lambda: int(input())
string = lambda: input().rstrip()
get_list = lambda: list(read())
read = lambda: map(int, input().split())
get_float = lambda: map(float, input().split())
# from bisect import bisect_left as lower_bound;
# from bisect import bisect_right as upper_bound;
# from math import ceil, factorial;

 
def ceil(x):
    if x != int(x):
        x = int(x) + 1
    return x
 
def factorial(x, m):
	val = 1
	while x>0:
		val = (val * x) % m
		x -= 1
	return val

def fact(x):
	val = 1
	while x > 0:
		val *= x
		x -= 1
	return val
    
# swap_array function
def swaparr(arr, a,b):
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
 
## gcd function
def gcd(a,b):
    if b == 0:
        return a;
    return gcd(b, a % b);

## lcm function
def lcm(a, b):
	return (a * b) // math.gcd(a, b)

def is_integer(n):
	return math.ceil(n) == math.floor(n)
 
## nCr function efficient using Binomial Cofficient
def nCr(n, k): 
	if k > n:
		return 0
	if(k > n - k):
		k = n - k
	res = 1
	for i in range(k):
		res = res * (n - i)
		res = res / (i + 1)
	return int(res)
 
## upper bound function code -- such that e in a[:i] e < x;

 
## prime factorization
def primefs(n):
    ## if n == 1    ## calculating primes
    primes = {}
    while(n%2 == 0 and n > 0):
        primes[2] = primes.get(2, 0) + 1
        n = n//2
    for i in range(3, int(n**0.5)+2, 2):
        while(n%i == 0 and n > 0):
            primes[i] = primes.get(i, 0) + 1
            n = n//i
    if n > 2:
        primes[n] = primes.get(n, 0) + 1
    ## prime factoriazation of n is stored in dictionary
    ## primes and can be accesed. O(sqrt n)
    return primes
 
## MODULAR EXPONENTIATION FUNCTION
def power(x, y, p):
    if y == 0:
        return 1
    res = 1
    x = x % p  
    if (x == 0) : 
        return 0
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1      
        x = (x * x) % p 
    return res 
 
## DISJOINT SET UNINON FUNCTIONS
def swap(a,b):
    temp = a
    a = b
    b = temp
    return a,b;
 
# find function with path compression included (recursive)
# def find(x, link):
#     if link[x] == x:
#         return x
#     link[x] = find(link[x], link);
#     return link[x];
 
# find function with path compression (ITERATIVE)
def find(x, link):
    p = x;
    while( p != link[p]):
        p = link[p];
    
    while( x != p):
        nex = link[x];
        link[x] = p;
        x = nex;
    return p;
 
 
# the union function which makes union(x,y)
# of two nodes x and y
def union(x, y, link, size):
    x = find(x, link)
    y = find(y, link)
    if size[x] < size[y]:
        x,y = swap(x,y)
    if x != y:
        size[x] += size[y]
        link[y] = x
 
## returns an array of boolean if primes or not USING SIEVE OF ERATOSTHANES
def sieve(n): 
    prime = [True for i in range(n+1)] 
    prime[0], prime[1] = False, False
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    return prime

# Euler's Toitent Function phi
def phi(n) : 
  
    result = n 
    p = 2
    while(p * p<= n) : 
        if (n % p == 0) : 
            while (n % p == 0) : 
                n = n // p 
            result = result * (1.0 - (1.0 / (float) (p))) 
        p = p + 1
    if (n > 1) : 
        result = result * (1.0 - (1.0 / (float)(n))) 
   
    return (int)(result) 

def is_prime(n):
	if n == 0:
		return False
	if n == 1:
		return True
	for i in range(2, int(n ** (1 / 2)) + 1):
		if not n % i:
			return False
 
	return True

def next_prime(n, primes):
	while primes[n] != True:
		n += 1
	return n

 
#### PRIME FACTORIZATION IN O(log n) using Sieve ####
MAXN = int(1e5 + 5)
def spf_sieve():
    spf[1] = 1;
    for i in range(2, MAXN):
        spf[i] = i;
    for i in range(4, MAXN, 2):
        spf[i] = 2;
    for i in range(3, ceil(MAXN ** 0.5), 2):
        if spf[i] == i:
            for j in range(i*i, MAXN, i):
                if spf[j] == j:
                    spf[j] = i;
    ## function for storing smallest prime factors (spf) in the array
 
################## un-comment below 2 lines when using factorization #################
spf = [0 for i in range(MAXN)]
# spf_sieve();
def factoriazation(x):
    res = []
    for i in range(2, int(x ** 0.5) + 1):
    	while x % i == 0:
    		res.append(i)
    		x //= i
    if x != 1:
   		res.append(x)
    return res
    ## this function is useful for multiple queries only, o/w use
    ## primefs function above. complexity O(log n)

def factors(n):
	res = []
	for i in range(1, int(n ** 0.5) + 1):
		if n % i == 0:
			res.append(i)
			res.append(n // i)
	return list(set(res))
 
## taking integer array input
def int_array():
    return list(map(int, input().strip().split()));
 
def float_array():
    return list(map(float, input().strip().split()));
 
## taking string array input
def str_array():
    return input().strip().split();

def binary_search(low, high, w, h, n):
	while low < high:
		mid = low + (high - low) // 2
		# print(low, mid, high)
		if check(mid, w, h, n):
			low = mid + 1
		else:
			high = mid
	return low

## for checking any conditions
def check(moves, n):
	val = (moves + 1) // 2
	rem = moves - val
	sol = (val + 1) * (rem + 1)
	return sol < n
	

## for sorting according to second position
def sortSecond(val):
	return val[1]
	

 
#defining a couple constants
MOD = int(1e9)+7;
CMOD = 998244353;
INF = float('inf'); NINF = -float('inf');
alphs = "abcdefghijklmnopqrstuvwxyz"
 
################### ---------------- TEMPLATE ENDS HERE ---------------- ###################
 
from itertools import permutations
import math
import bisect as bis
import random
import sys
import collections as collect
import functools as fnt
from decimal import Decimal
# from sys import stdout
# import numpy as np
"""
_______________
rough work here
_______________

n cross roads in the line in the town
either bus or the tram station at each crossroad


"""

def solve():
    n = scanner()
    a = get_list()
    if len(set(a)) == n:
        print("NO")
    else:
        print("YES")
        



# region fastio
# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()
 
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
 
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
 
 
if __name__ == "__main__":
    #read()
    # sys.stdin = open("input.txt", "r")
    # sys.stdout = open("output.txt", "w")
    t = scanner()
    for i in range(t):
    	solve()
    #dmain()
 
# Comment Read()
	# fin_time = datetime.now()
# 	print("Execution time (for loop): ", (fin_time-init_time))
