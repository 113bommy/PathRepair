import sys
import os
from io import BytesIO, IOBase

#########################
# imgur.com/Pkt7iIf.png #
#########################

# returns the list of prime numbers less than or equal to n:
'''def sieve(n):
    if n < 2: return list()
    prime = [True for _ in range(n + 1)]
    p = 3
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 2
    r = [2]
    for p in range(3, n + 1, 2):
        if prime[p]:
            r.append(p)
    return r'''

# returns all the divisors of a number n(takes an additional parameter start):
'''def divs(n, start=1):
    divisors = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if n / i == i:
                divisors.append(i)
            else:
                divisors.extend([i, n // i])
    return divisors'''

# returns the number of factors of a given number if a primes list is given:
'''def divn(n, primes):
    divs_number = 1
    for i in primes:
        if n == 1:
            return divs_number
        t = 1
        while n % i == 0:
            t += 1
            n //= i
        divs_number *= t
    return divs_number'''

# returns the leftmost and rightmost positions of x in a given list d(if x isnot present then returns (-1,-1)):
'''def flin(d, x, default=-1):
    left = right = -1
    for i in range(len(d)):
        if d[i] == x:
            if left == -1: left = i
            right = i
    if left == -1:
        return (default, default)
    else:
        return (left, right)'''

# returns (b**p)%m 
'''def modpow(b,p,m):
    res=1
    b=b%m
    while(p):
        if p&1:
            res=(res*b)%m
        b=(b*b)%m
        p>>=1
    return res'''

# if m is a prime this can be used to determine (1//a)%m or modular multiplicative inverse of a number a
'''def mod_inv(a,m):
    return modpow(a,m-2,m)'''

# returns the ncr%m for (if m is a prime number) for very large n and r
'''def ncr(n,r,m):
    res=1
    if r==0:
        return 1
    if n-r<r:
        r=n-r
    p,k=1,1
    while(r):
        res=((res%m)*(((n%m)*mod_inv(r,m))%m))%m
        n-=1
        r-=1
    return res'''

# returns ncr%m (if m is a prime number and there should be a list fact which stores the factorial values upto n):
'''def ncrlis(n,r,m):
    return (fact[n]*(mod_inv(fact[r],m)*mod_inv(fact[n-r],m))%m)%m'''

#factorial list which stores factorial of values upto n:
'''mx_lmt=10**5+10
fact=[1 for i in range(mx_lmt)]
for i in range(1,mx_lmt):
    fact[i]=(i*fact[i-1])%mod'''

#count xor of numbers from 1 to n:
'''def xor1_n(n):
    d={0:n,1:1,2:n+1,3:0}
    return d[n&3]'''

def ceil(n, k): return n // k + (n % k != 0)
def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def lcm(a, b): return abs(a * b) // math.gcd(a, b)
def prr(a, sep=' '): print(sep.join(map(str, a)))
def dd(): return defaultdict(int)
def ddl(): return defaultdict(list)
def ddd(): return defaultdict(defaultdict(int))
 

# region fastio
 
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
 

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

from collections import defaultdict 
#from collections import deque
#from collections import OrderedDict
#from math import gcd
#import time
#import itertools
#import timeit
#import random
#from bisect import bisect_left as bl
#from bisect import bisect_right as br
#from bisect import insort_left as il
#from bisect import insort_right as ir
#from heapq import *
#mod=998244353
#mod=10**9+7

for _ in range(1):
    n=ii()
    a=li()
    print(2+(a[2]^min(a)))
