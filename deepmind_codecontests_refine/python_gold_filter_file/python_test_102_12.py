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

class LazySegUpdate():
    def __init__(self, N):
        self.N = N
        n = 4 * N
        self.tree = [0] * n
        self.lazy = [0] * n
        
    def queryHelper(self, index, s, e, l, r):
        if self.lazy[index]:
            # Apply lazy to node.
            update = self.lazy[index]
            self.lazy[index] = 0
            self.tree[index] = max(self.tree[index], update)
            # Check if this is leaf.
            if s != e:
                self.lazy[2 * index] = max(self.lazy[2 * index], update)
                self.lazy[2 * index + 1] = max(self.lazy[2 * index + 1], update)
                
        if s > e or s > r or e < l:
            return 0
        if s >= l and e <= r:
            return self.tree[index]
        # Overlapped.
        mid = (s + e) // 2
        return max(self.queryHelper(2 * index, s, mid, l, r), self.queryHelper(2 * index + 1, mid + 1, e, l, r))
    
    def updateHelper(self, index, s, e, l, r, h):
        if self.lazy[index]:
            # Apply lazy to node.
            update = self.lazy[index]
            self.lazy[index] = 0
            self.tree[index] = max(self.tree[index], update)
            
            if s != e:
                self.lazy[2 * index] = max(self.lazy[2 * index], update)
                self.lazy[2 * index + 1] = max(self.lazy[2 * index + 1], update)
                
        if s > e or s > r or e < l:
            return
        if s >= l and e <= r:
            self.tree[index] = max(self.tree[index], h)
            if s != e:
                self.lazy[2 * index] = max(self.lazy[2 * index], h)
                self.lazy[2 * index + 1] = max(self.lazy[2 * index + 1], h)
            return
        
        mid = (s + e) // 2
        self.updateHelper(2 * index, s, mid, l, r, h)
        self.updateHelper(2 * index + 1, mid + 1, e, l, r, h)
        self.tree[index] = max(self.tree[2 * index], self.tree[2 * index + 1])
        
    def query(self, l, r):
        return self.queryHelper(1, 0, self.N - 1, l, r - 1)
    
    def update(self, l, r, h):
        self.updateHelper(1, 0, self.N - 1, l, r - 1, h)
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
#-----------------------------------Sorted List------------------------------------------
class SortedList:
    def __init__(self, iterable=[], _load=200):
        """Initialize sorted list instance."""
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self._list_lens = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self._fen_tree = []
        self._rebuild = True
 
    def _fen_build(self):
        """Build a fenwick tree instance."""
        self._fen_tree[:] = self._list_lens
        _fen_tree = self._fen_tree
        for i in range(len(_fen_tree)):
            if i | i + 1 < len(_fen_tree):
                _fen_tree[i | i + 1] += _fen_tree[i]
        self._rebuild = False
 
    def _fen_update(self, index, value):
        """Update `fen_tree[index] += value`."""
        if not self._rebuild:
            _fen_tree = self._fen_tree
            while index < len(_fen_tree):
                _fen_tree[index] += value
                index |= index + 1
 
    def _fen_query(self, end):
        """Return `sum(_fen_tree[:end])`."""
        if self._rebuild:
            self._fen_build()
 
        _fen_tree = self._fen_tree
        x = 0
        while end:
            x += _fen_tree[end - 1]
            end &= end - 1
        return x
 
    def _fen_findkth(self, k):
        """Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
        _list_lens = self._list_lens
        if k < _list_lens[0]:
            return 0, k
        if k >= self._len - _list_lens[-1]:
            return len(_list_lens) - 1, k + _list_lens[-1] - self._len
        if self._rebuild:
            self._fen_build()
 
        _fen_tree = self._fen_tree
        idx = -1
        for d in reversed(range(len(_fen_tree).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                idx = right_idx
                k -= _fen_tree[idx]
        return idx + 1, k
 
    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`."""
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens
 
        self._len -= 1
        self._fen_update(pos, -1)
        del _lists[pos][idx]
        _list_lens[pos] -= 1
 
        if _list_lens[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del _list_lens[pos]
            del _mins[pos]
            self._rebuild = True
 
    def _loc_left(self, value):
        """Return an index pair that corresponds to the first position of `value` in the sorted list."""
        if not self._len:
            return 0, 0
 
        _lists = self._lists
        _mins = self._mins
 
        lo, pos = -1, len(_lists) - 1
        while lo + 1 < pos:
            mi = (lo + pos) >> 1
            if value <= _mins[mi]:
                pos = mi
            else:
                lo = mi
 
        if pos and value <= _lists[pos - 1][-1]:
            pos -= 1
 
        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value <= _list[mi]:
                idx = mi
            else:
                lo = mi
 
        return pos, idx
 
    def _loc_right(self, value):
        """Return an index pair that corresponds to the last position of `value` in the sorted list."""
        if not self._len:
            return 0, 0
 
        _lists = self._lists
        _mins = self._mins
 
        pos, hi = 0, len(_lists)
        while pos + 1 < hi:
            mi = (pos + hi) >> 1
            if value < _mins[mi]:
                hi = mi
            else:
                pos = mi
 
        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value < _list[mi]:
                idx = mi
            else:
                lo = mi
 
        return pos, idx
 
    def add(self, value):
        """Add `value` to sorted list."""
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens
 
        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self._fen_update(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            _list_lens[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                _list_lens.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                _list_lens[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            _list_lens.append(1)
            self._rebuild = True
 
    def discard(self, value):
        """Remove `value` from sorted list if it is a member."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)
 
    def remove(self, value):
        """Remove `value` from sorted list; `value` must be a member."""
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))
 
    def pop(self, index=-1):
        """Remove and return value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value
 
    def bisect_left(self, value):
        """Return the first index to insert `value` in the sorted list."""
        pos, idx = self._loc_left(value)
        return self._fen_query(pos) + idx
 
    def bisect_right(self, value):
        """Return the last index to insert `value` in the sorted list."""
        pos, idx = self._loc_right(value)
        return self._fen_query(pos) + idx
 
    def count(self, value):
        """Return number of occurrences of `value` in the sorted list."""
        return self.bisect_right(value) - self.bisect_left(value)
 
    def __len__(self):
        """Return the size of the sorted list."""
        return self._len
 
    def __getitem__(self, index):
        """Lookup value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        return self._lists[pos][idx]
 
    def __delitem__(self, index):
        """Remove value at `index` from sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._delete(pos, idx)
 
    def __contains__(self, value):
        """Return true if `value` is an element of the sorted list."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False
 
    def __iter__(self):
        """Return an iterator over the sorted list."""
        return (value for _list in self._lists for value in _list)
 
    def __reversed__(self):
        """Return a reverse iterator over the sorted list."""
        return (value for _list in reversed(self._lists) for value in reversed(_list))
 
    def __repr__(self):
        """Return string representation of sorted list."""
        return 'SortedList({0})'.format(list(self))
#---------------------------------Binary Search------------------------------------------
def binarySearch(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res = n
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid] >= key):
            res=mid
            right = mid-1
        else:
            left = mid + 1
    return res

def binarySearch1(arr, n, key):
    left = 0
    right = n-1
    mid = 0
    res=-1
    while (left <= right):
        mid = (right + left)//2
        if (arr[mid] > key):
            right = mid-1
        else:
            res=mid
            left = mid + 1
    return res
#---------------------------------running code------------------------------------------
tt=1
tt=int(input())
for _ in range (tt):
    #input()
    #n=int(input())
    n,m=map(int,input().split())
    #a=list(map(int,input().split()))
    #b=list(map(int,input().split()))
    s=input()
    #n=len(s)
    side=0
    top=0
    ans=[n,m]
    lm,rm,tm,bm=[0]*4
    for i in s:
        if i=='L':
            side-=1
        elif i=='R':
            side+=1
        elif i=='U':
            top-=1
        else:
            top+=1
        lm=min(lm,side)
        rm=max(rm,side)
        tm=max(tm,top)
        bm=min(bm,top)
        if rm-lm>=m or tm-bm>=n:
            break
        ans=[1-bm,1-lm]
    print(*ans)