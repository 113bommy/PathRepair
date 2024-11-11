#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
import io
from fractions import Fraction
import collections
from itertools import permutations
from collections import defaultdict
from collections import deque
from collections import Counter
import threading

#sys.setrecursionlimit(300000)
#threading.stack_size(10**8)

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

#-------------------game starts now-----------------------------------------------------
#mod = 9223372036854775807  
class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: max(a,b)):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def __delitem__(self, idx):
        self[idx] = self._default
 
    def __getitem__(self, idx):
        return self.data[idx + self._size]
 
    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def __len__(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size
 
        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res
 
    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
    
class SegmentTree1:
    def __init__(self, data, default=0, func=lambda a, b: a+b):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def __delitem__(self, idx):
        self[idx] = self._default
 
    def __getitem__(self, idx):
        return self.data[idx + self._size]
 
    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def __len__(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size
 
        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res
 
    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
    
MOD=10**9+7
class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]
 
    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]
 
    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]
 
    def invFactorial(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  # To make sure already calculated n^-1
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]
 
 
class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)
 
    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.invFactorial(max(n - k, k)) * f.invFactorial(min(k, n - k)) % self.MOD
mod=10**9+7
omod=998244353
#-------------------------------------------------------------------------
prime = [True for i in range(10001)] 
prime[0]=prime[1]=False
#pp=[0]*10000
def SieveOfEratosthenes(n=10000):
    p = 2
    c=0
    while (p <= n): 
          
        if (prime[p] == True):
            c+=1
            for i in range(p, n+1, p): 
                #pp[i]=1
                prime[i] = False
        p += 1
#-----------------------------------DSU--------------------------------------------------
class DSU:
    def __init__(self, R, C):
        #R * C is the source, and isn't a grid square
        self.par = range(R*C + 1)
        self.rnk = [0] * (R*C + 1)
        self.sz = [1] * (R*C + 1)

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr: return
        if self.rnk[xr] < self.rnk[yr]:
            xr, yr = yr, xr
        if self.rnk[xr] == self.rnk[yr]:
            self.rnk[xr] += 1

        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]

    def size(self, x):
        return self.sz[self.find(x)]

    def top(self):
        # Size of component at ephemeral "source" node at index R*C,
        # minus 1 to not count the source itself in the size
        return self.size(len(self.sz) - 1) - 1
#---------------------------------Lazy Segment Tree--------------------------------------
# https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
class LazySegTree:
    def __init__(self, _op, _e, _mapping, _composition, _id, v):
        def set(p, x):
            assert 0 <= p < _n
            p += _size
            for i in range(_log, 0, -1):
                _push(p >> i)
            _d[p] = x
            for i in range(1, _log + 1):
                _update(p >> i)
 
        def get(p):
            assert 0 <= p < _n
            p += _size
            for i in range(_log, 0, -1):
                _push(p >> i)
            return _d[p]
 
        def prod(l, r):
            assert 0 <= l <= r <= _n
 
            if l == r:
                return _e
 
            l += _size
            r += _size
 
            for i in range(_log, 0, -1):
                if ((l >> i) << i) != l:
                    _push(l >> i)
                if ((r >> i) << i) != r:
                    _push(r >> i)
 
            sml = _e
            smr = _e
            while l < r:
                if l & 1:
                    sml = _op(sml, _d[l])
                    l += 1
                if r & 1:
                    r -= 1
                    smr = _op(_d[r], smr)
                l >>= 1
                r >>= 1
 
            return _op(sml, smr)
 
        def apply(l, r, f):
            assert 0 <= l <= r <= _n
            if l == r:
                return
 
            l += _size
            r += _size
 
            for i in range(_log, 0, -1):
                if ((l >> i) << i) != l:
                    _push(l >> i)
                if ((r >> i) << i) != r:
                    _push((r - 1) >> i)
 
            l2 = l
            r2 = r
            while l < r:
                if l & 1:
                    _all_apply(l, f)
                    l += 1
                if r & 1:
                    r -= 1
                    _all_apply(r, f)
                l >>= 1
                r >>= 1
            l = l2
            r = r2
 
            for i in range(1, _log + 1):
                if ((l >> i) << i) != l:
                    _update(l >> i)
                if ((r >> i) << i) != r:
                    _update((r - 1) >> i)
 
        def _update(k):
            _d[k] = _op(_d[2 * k], _d[2 * k + 1])
 
        def _all_apply(k, f):
            _d[k] = _mapping(f, _d[k])
            if k < _size:
                _lz[k] = _composition(f, _lz[k])
 
        def _push(k):
            _all_apply(2 * k, _lz[k])
            _all_apply(2 * k + 1, _lz[k])
            _lz[k] = _id
 
        _n = len(v)
        _log = _n.bit_length()
        _size = 1 << _log
        _d = [_e] * (2 * _size)
        _lz = [_id] * _size
        for i in range(_n):
            _d[_size + i] = v[i]
        for i in range(_size - 1, 0, -1):
            _update(i)
 
        self.set = set
        self.get = get
        self.prod = prod
        self.apply = apply
 
 
MIL = 1 << 20
 
 
def makeNode(total, count):
    # Pack a pair into a float
    return (total * MIL) + count
 
 
def getTotal(node):
    return math.floor(node / MIL)
 
 
def getCount(node):
    return node - getTotal(node) * MIL
 
 
nodeIdentity = makeNode(0.0, 0.0)
 
 
def nodeOp(node1, node2):
    return node1 + node2
    # Equivalent to the following:
    return makeNode(
        getTotal(node1) + getTotal(node2), getCount(node1) + getCount(node2)
    )
 
 
identityMapping = -1
 
 
def mapping(tag, node):
    if tag == identityMapping:
        return node
    # If assigned, new total is the number assigned times count
    count = getCount(node)
    return makeNode(tag * count, count)
 
 
def composition(mapping1, mapping2):
    # If assigned multiple times, take first non-identity assignment
    return mapping1 if mapping1 != identityMapping else mapping2
#---------------------------------Pollard rho--------------------------------------------
def memodict(f):
    """memoization decorator for a function taking a single argument"""
    class memodict(dict):
        def __missing__(self, key):
            ret = self[key] = f(key)
            return ret
 
    return memodict().__getitem__
 
 
def pollard_rho(n):
    """returns a random factor of n"""
    if n & 1 == 0:
        return 2
    if n % 3 == 0:
        return 3
 
    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            prev = p
            p = (p * p) % n
            if p == 1:
                return math.gcd(prev - 1, n)
            if p == n - 1:
                break
        else:
            for i in range(2, n):
                x, y = i, (i * i + 1) % n
                f = math.gcd(abs(x - y), n)
                while f == 1:
                    x, y = (x * x + 1) % n, (y * y + 1) % n
                    y = (y * y + 1) % n
                    f = math.gcd(abs(x - y), n)
                if f != n:
                    return f
    return n
 
 
@memodict
def prime_factors(n):
    """returns a Counter of the prime factorization of n"""
    if n <= 1:
        return Counter()
    f = pollard_rho(n)
    return Counter([n]) if f == n else prime_factors(f) + prime_factors(n // f)
 
 
def distinct_factors(n):
    """returns a list of all distinct factors of n"""
    factors = [1]
    for p, exp in prime_factors(n).items():
        factors += [p**i * factor for factor in factors for i in range(1, exp + 1)]
    return factors
 
 
def all_factors(n):
    """returns a sorted list of all distinct factors of n"""
    small, large = [], []
    for i in range(1, int(n**0.5) + 1, 2 if n & 1 else 1):
        if not n % i:
            small.append(i)
            large.append(n // i)
    if small[-1] == large[-1]:
        large.pop()
    large.reverse()
    small.extend(large)
    return small
#---------------------------------Binary Search------------------------------------------
def binarySearch(arr, n,i, key):
    left = 0
    right = n-1
    mid = 0
    res=n
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid][i] > key):
            res=mid
            right = mid-1
        else:
            left = mid + 1
    return res

def binarySearch1(arr, n,i, key):
    left = 0
    right = n-1
    mid = 0
    res=-1
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid][i] > key):
            right = mid-1
        else:
            res=mid
            left = mid + 1
    return res
#---------------------------------running code------------------------------------------
t=1
t=int(input())
for _ in range (t):
    n=int(input())
    #n,m=map(int,input().split())
    a=list(map(int,input().split()))
    #tp=list(map(int,input().split()))
    #s=input()
    b=[[a[i],i]for i in range (n)]
    d=defaultdict(list)
    b.sort()
    #print(b)
    for i in range (n):
        c=(abs(b[i][1]-i))%2
        if not c:
            if d[b[i][0]] and d[b[i][0]][-1]==0:
                d[b[i][0]].pop()
            else:
                d[b[i][0]].append(0)
        else:
            if d[b[i][0]] and d[b[i][0]][-1]==1:
                d[b[i][0]].pop()
            else:
                d[b[i][0]].append(1)
    #print(d)
    ch=1
    for i in d:
        if sum(d[i]):
            ch=0
            break
    if ch:
        print("YES")
    else:
        print("NO")