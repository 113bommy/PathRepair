# ---------------------------iye ha aam zindegi---------------------------------------------
import math
import random
import heapq, bisect
import sys
from collections import deque, defaultdict
from fractions import Fraction
import sys
# import threading
from math import inf, log2
from collections import defaultdict

# threading.stack_size(10**8)
mod = 10 ** 9 + 7
mod1 = 998244353

# ------------------------------warmup----------------------------
import os
import sys
from io import BytesIO, IOBase

# sys.setrecursionlimit(300000)

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
#----------------------------------------------------------------------------------------------------------------
class LazySegmentTree:
    def __init__(self, array, func=max):
        self.n = len(array)
        self.size = 2**(int(log2(self.n-1))+1) if self.n != 1 else 1
        self.func = func
        self.default = 0 if self.func != min else inf
        self.data = [self.default] * (2 * self.size)
        self.lazy = [0] * (2 * self.size)
        self.process(array)

    def process(self, array):
        self.data[self.size : self.size+self.n] = array
        for i in range(self.size-1, -1, -1):
            self.data[i] = self.func(self.data[2*i], self.data[2*i+1])

    def push(self, index):
        """Push the information of the root to it's children!"""
        self.lazy[2*index] += self.lazy[index]
        self.lazy[2*index+1] += self.lazy[index]
        self.data[2 * index] += self.lazy[index]
        self.data[2 * index + 1] += self.lazy[index]
        self.lazy[index] = 0

    def build(self, index):
        """Build data with the new changes!"""
        index >>= 1
        while index:
            self.data[index] = self.func(self.data[2*index], self.data[2*index+1]) + self.lazy[index]
            index >>= 1

    def query(self, alpha, omega):
        """Returns the result of function over the range (inclusive)!"""
        res = self.default
        alpha += self.size
        omega += self.size + 1
        for i in range(len(bin(alpha)[2:])-1, 0, -1):
            self.push(alpha >> i)
        for i in range(len(bin(omega-1)[2:])-1, 0, -1):
            self.push((omega-1) >> i)
        while alpha < omega:
            if alpha & 1:
                res = self.func(res, self.data[alpha])
                alpha += 1
            if omega & 1:
                omega -= 1
                res = self.func(res, self.data[omega])
            alpha >>= 1
            omega >>= 1
        return res

    def update(self, alpha, omega, value):
        """Increases all elements in the range (inclusive) by given value!"""
        alpha += self.size
        omega += self.size + 1
        l, r = alpha, omega
        while alpha < omega:
            if alpha & 1:
                self.data[alpha] += value
                self.lazy[alpha] += value
                alpha += 1
            if omega & 1:
                omega -= 1
                self.data[omega] += value
                self.lazy[omega] += value
            alpha >>= 1
            omega >>= 1
        self.build(l)
        self.build(r-1)
#---------------------------------------------------------------------------------------------
class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a + b):
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


# -------------------------------iye ha chutiya zindegi-------------------------------------
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


# --------------------------------------iye ha combinations ka zindegi---------------------------------
def powm(a, n, m):
    if a == 1 or n == 0:
        return 1
    if n % 2 == 0:
        s = powm(a, n // 2, m)
        return s * s % m
    else:
        return a * powm(a, n - 1, m) % m


# --------------------------------------iye ha power ka zindegi---------------------------------
def sort_list(list1, list2):
    zipped_pairs = zip(list2, list1)

    z = [x for _, x in sorted(zipped_pairs)]

    return z


# --------------------------------------------------product----------------------------------------
def product(l):
    por = 1
    for i in range(len(l)):
        por *= l[i]
    return por


# --------------------------------------------------binary----------------------------------------
def binarySearchCount(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        # Check if middle element is
        # less than or equal to key
        if (arr[mid] < key):
            count = mid + 1
            left = mid + 1

        # If key is smaller, ignore right half
        else:
            right = mid - 1

    return count


# --------------------------------------------------binary----------------------------------------
def countdig(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c
def binary(x, length):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y

def countGreater(arr, n, k):
    l = 0
    r = n - 1

    # Stores the index of the left most element
    # from the array which is greater than k
    leftGreater = n

    # Finds number of elements greater than k
    while (l <= r):
        m = int(l + (r - l) / 2)
        if (arr[m] >= k):
            leftGreater = m
            r = m - 1

        # If mid element is less than
        # or equal to k update l
        else:
            l = m + 1

    # Return the count of elements
    # greater than k
    return (n - leftGreater)


# --------------------------------------------------binary------------------------------------
class Node:
    def __init__(self, data):
        self.data = data
        self.count = 0
        self.left = None  # left node for 0
        self.right = None  # right node for 1


class BinaryTrie:
    def __init__(self):
        self.root = Node(0)

    def insert(self, pre_xor):
        self.temp = self.root
        k = 1 << 32
        for i in range(31, -1, -1):
            k //= 2
            val = pre_xor & k
            if val:
                if not self.temp.right:
                    self.temp.right = Node(0)
                self.temp = self.temp.right
                self.temp.count += 1
            if not val:
                if not self.temp.left:
                    self.temp.left = Node(0)
                self.temp = self.temp.left
                self.temp.count += 1
        self.temp.data = pre_xor

    def query(self, p):
        ans = 0
        self.temp = self.root
        k = 1 << 32
        for i in range(31, -1, -1):
            k //= 2
            val = p & k
            if val == 0:
                if self.temp.right and self.temp.right.count > 0:
                    self.temp = self.temp.right
                    ans ^= k
                else:
                    self.temp = self.temp.left
            else:
                if self.temp.left and self.temp.left.count > 0:
                    self.temp = self.temp.left
                    ans ^= k
                else:
                    self.temp = self.temp.right
        return ans
# -------------------------bin trie-------------------------------------------
for ik in range(int(input())):
    n,c=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    def find(x):
        cur=0
        days=x
        now=0
        while(True):
            if now+days*a[cur]>=c:
                return True
            else:
                if cur==len(a)-1:
                    return False
                t=min(days,int(math.ceil((b[cur]-now)/a[cur]))+1)
                days-=t
                now+=(t-1)*a[cur]-b[cur]
                cur+=1
            if days==0:
                if now<c:
                    return False
                return True
    st=1
    end=int(math.ceil(c/a[0]))
    ans=end
    while(st<=end):
        mid=(st+end)//2
        if find(mid)==True:
            ans=mid
            end=mid-1
        else:
            st=mid+1
    print(ans)

