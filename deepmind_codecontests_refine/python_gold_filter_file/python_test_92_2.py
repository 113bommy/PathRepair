from math import *
from collections import *
import os
from io import BytesIO, IOBase
import sys
 
sys.setrecursionlimit(10 ** 6)
MOD = 1000000007
 
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
 
# Code by Big Dick Daddy Dick

def binpow(a, b, m):
    a %= m
    x = 1
    while b > 0:
        if b & 1:
            x = x * a % m
        a = a * a % m
        b >>= 1
    return x


def sakurajima(n):
    d = defaultdict(list)
    if n < 9:
        n = 10
    l = [1] * n
    for i in range(2, int(n ** 0.5) + 1):
        if l[i - 1] == 1:
            for j in range(2 * i, n + 1, i):
                if j % i == 0:
                    l[j - 1] = 0
                    d[j].append(i)
    return d


def binser(arr, l, r, x):
    while l < r:
        mid = l + (r - l) // 2
        # print(l, r, mid)

        if arr[mid] == x:
            return mid

        elif arr[mid] < x:
            l = mid + 1

        else:
            r = mid - 1

    return mid

def lcm(a, b):
    return (a * b) // gcd(a, b)

def sod(n):
    l = list(str(n))
    s = 0
    for i in l:
        s += int(i)
    return s


def prime_factors(num):   
    l =[]
    if num % 2:
        l.append(2)
    while num % 2 == 0:  
        num = num / 2  
  
    for i in range(3, int(sqrt(num)) + 1, 2):  
        if not num % i:
            l.append(i)
        while num % i == 0:  
            num = num / i
    if num > 2:
        l.append(num)
    return l


def factmod(n, p):

    f = defaultdict(int)
    f[0] = 1
    for i in range(1, n + 1):
        f[i] = (f[i-1] * i) % MOD

    """
    res = 1
    while (n > 1):
        if (n//p) % 2:
            res = p - res

        res = res * f[n%p] % p
        n //= p
    """

    return f



def largestPower(n, p):
     
    # Initialize result
    x = 0
     
    # Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n):
        n //= p
        x += n
    return x

def modFact(n, p) :
 
    if (n >= p) :
        return 0
 
    res = 1
    isPrime = [1] * (n + 1)
    i = 2
    while(i * i <= n):
        if (isPrime[i]):
            for j in range(2 * i, n, i) :
                isPrime[j] = 0
        i += 1
         
    # Consider all primes found by Sieve
    for i in range(2, n):
        if (isPrime[i]) :
             
            k = largestPower(n, i)
 
            # Multiply result with (i^k) % p
            res = (res * binpow(i, k, p)) % p
 
    return res

def dfs(ajl, now, vis):

    vis[now] = True

    for i in ajl[now]:
        if not vis[i]:
            dfs(ajl, i, vis)

def panda(s):
    n = len(s)
    x, y = 0, 0
    la, lb = [], []
    l = list(s)
    i = 0
    while i < n - 1:
        if i + 2 < n:
            if s[i:i + 3] == "aba" or s[i:i + 3] == "bab":
                i += 2
                continue
        if s[i:i + 2] == "ab":
            x += 1
            la.append(i)
        elif s[i:i + 2] == "ba":
            y += 1
            lb.append(i)
        i += 1
    if x == y:
        return s
    if x > y:
        l[0] = 'b'
    else:
        l[-1] = 'b'
    return "".join(l)

# Code by Big Dick Daddy Dick

# n = int(input())
# n, k = map(int, input().split())
# s = input()
# l = list(map(int, input().split()))
# memo = [[-1 for i in range(n + 1)] for j in range(2)]



t = int(input())
for _ in range(t):
    s = input()
    print(panda(s))