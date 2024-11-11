"""
    Author - Satwik Tiwari .
    24th Sept , 2020  - Thursday
"""

#===============================================================================================
#importing some useful libraries.


from __future__ import division, print_function
from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase


# from itertools import *
from heapq import *
from math import gcd, factorial,floor,ceil

from copy import deepcopy
from collections import deque


# from collections import Counter as counter  # Counter(list)  return a dict with {key: count}
# from itertools import combinations as comb # if a = [1,2,3] then print(list(comb(a,2))) -----> [(1, 2), (1, 3), (2, 3)]
# from itertools import permutations as permutate


from bisect import bisect_left as bl
from bisect import bisect_right as br
from bisect import bisect

#==============================================================================================
#fast I/O region
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

# inp = lambda: sys.stdin.readline().rstrip("\r\n")

#===============================================================================================
### START ITERATE RECURSION ###
from types import GeneratorType
def iterative(f, stack=[]):
  def wrapped_func(*args, **kwargs):
    if stack: return f(*args, **kwargs)
    to = f(*args, **kwargs)
    while True:
      if type(to) is GeneratorType:
        stack.append(to)
        to = next(to)
        continue
      stack.pop()
      if not stack: break
      to = stack[-1].send(to)
    return to
  return wrapped_func
#### END ITERATE RECURSION ####

#===============================================================================================
#some shortcuts

mod = 10**9+7
def inp(): return sys.stdin.readline().rstrip("\r\n") #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
# def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  #as stdout.write always print sring.
def testcase(t):
    for pp in range(t):
        solve(pp)
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def google(p):
    print('Case #'+str(p)+': ',end='')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(x, y, p) :
    res = 1     # Initialize result
    x = x % p  # Update x if it is more , than or equal to p
    if (x == 0) :
        return 0
    while (y > 0) :
        if ((y & 1) == 1) : # If y is odd, multiply, x with result
            res = (res * x) % p

        y = y >> 1      # y = y/2
        x = (x * x) % p
    return res
# def ncr(n,r): return factorial(n) // (factorial(r) * factorial(max(n - r, 1)))
def isPrime(n) :
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
    return True

#===============================================================================================
# code here ;))
N = 3*(10**5+1)

# array to store inverse of 1 to N
factorialNumInverse = [None] * (N + 1)

# array to precompute inverse of 1! to N!
naturalNumInverse = [None] * (N + 1)

# array to store factorial of
# first N numbers
fact = [None] * (N + 1)

# Function to precompute inverse of numbers
def InverseofNumber(p):
    naturalNumInverse[0] = naturalNumInverse[1] = 1
    for i in range(2, N + 1, 1):
        naturalNumInverse[i] = (naturalNumInverse[p % i] *
                                   (p - int(p / i)) % p)

# Function to precompute inverse
# of factorials
def InverseofFactorial(p):
    factorialNumInverse[0] = factorialNumInverse[1] = 1

    # precompute inverse of natural numbers
    for i in range(2, N + 1, 1):
        factorialNumInverse[i] = (naturalNumInverse[i] *
                                  factorialNumInverse[i - 1]) % p

# Function to calculate factorial of 1 to N
def factorial(p):
    fact[0] = 1

    # precompute factorials
    for i in range(1, N + 1):
        fact[i] = (fact[i - 1] * i) % p

# Function to return nCr % p in O(1) time
def Binomial(N, R, p):

    # n C r = n!*inverse(r!)*inverse((n-r)!)
    ans = ((fact[N] * factorialNumInverse[R])% p *
                      factorialNumInverse[N - R])% p
    return ans

def ncr(n, r, p):
    # initialize numerator
    # and denominator
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
            p - 2, p)) % p

def bucketsort(order, seq):
    buckets = [0] * (max(seq) + 1)
    for x in seq:
        buckets[x] += 1
    for i in range(len(buckets) - 1):
        buckets[i + 1] += buckets[i]

    new_order = [-1] * len(seq)
    for i in reversed(order):
        x = seq[i]
        idx = buckets[x] = buckets[x] - 1
        new_order[idx] = i

    return new_order


def ordersort(order, seq, reverse=False):
    bit = max(seq).bit_length() >> 1
    mask = (1 << bit) - 1
    order = bucketsort(order, [x & mask for x in seq])
    order = bucketsort(order, [x >> bit for x in seq])
    if reverse:
        order.reverse()
    return order


def long_ordersort(order, seq):
    order = ordersort(order, [int(i & 0x7fffffff) for i in seq])
    return ordersort(order, [int(i >> 31) for i in seq])


def multikey_ordersort(order, *seqs, sort=ordersort):
    for i in reversed(range(len(seqs))):
        order = sort(order, seqs[i])
    return order

def solve(case):
    n,k = sep()
    have = []
    left = []
    right = []

    for i in range(n):
        l,r = sep()
        left.append(l)
        right.append(0)
        left.append(r)
        right.append(1)
        # have.append([l,0])
        # have.append([r,1])
    temp = multikey_ordersort(range(2*n),left,right)
    have = []
    # print(temp)
    for i in temp:
        have.append((left[i],right[i]))
    # print(range(n))
    # print(have)
    cnt = 0
    currcnt = 0
    for i in range(len(have)):
        temp = have[i]
        # print(temp)
        if(temp[1] == 0):
            currcnt+=1
        else:
            currcnt-=1
            if(currcnt>=k-1):
                cnt += Binomial(currcnt,k-1,998244353 )
                cnt%=998244353
        # print(cnt)
    # print(cnt)
    print(cnt%998244353)

p = 998244353
InverseofNumber(p)
InverseofFactorial(p)
factorial(p)

testcase(1)
# testcase(int(inp()))









