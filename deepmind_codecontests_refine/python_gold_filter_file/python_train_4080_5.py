import os
import sys
from io import BytesIO, IOBase
import math
from queue import Queue
import collections
import itertools
import bisect
import heapq
#sys.setrecursionlimit(100000)
#^^^TAKE CARE FOR MEMORY LIMIT^^^
import random
def main():
    pass
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


def binary(n):
    return (bin(n).replace("0b", ""))


def decimal(s):
    return (int(s, 2))


def pow2(n):
    p = 0
    while (n > 1):
        n //= 2
        p += 1
    return (p)


def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            l.append(i)
            n = n / i
    if n > 2:
        l.append(int(n))
    return (l)


def isPrime(n):
    if (n == 1):
        return (False)
    else:
        root = int(n ** 0.5)
        root += 1
        for i in range(2, root):
            if (n % i == 0):
                return (False)
        return (True)


def maxPrimeFactors(n):
    maxPrime = -1
    while n % 2 == 0:
        maxPrime = 2
        n >>= 1
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            maxPrime = i
            n = n / i
    if n > 2:
        maxPrime = n
    return int(maxPrime)


def countcon(s, i):
    c = 0
    ch = s[i]
    for i in range(i, len(s)):
        if (s[i] == ch):
            c += 1
        else:
            break
    return (c)


def lis(arr):
    n = len(arr)
    lis = [1] * n
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1
    maximum = 0
    for i in range(n):
        maximum = max(maximum, lis[i])
    return maximum
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
    j = 0
    i = 0
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j + 1
        i = i + 1
    return j == m
def maxfac(n):
    root = int(n ** 0.5)
    for i in range(2, root + 1):
        if (n % i == 0):
            return (n // i)
    return (n)
def p2(n):
    c=0
    while(n%2==0):
        n//=2
        c+=1
    return c
def seive(n):
    primes=[True]*(n+1)
    primes[1]=primes[0]=False
    i=2
    while(i*i<=n):
        if(primes[i]==True):
            for j in range(i*i,n+1,i):
                primes[j]=False
        i+=1
    pr=[]
    for i in range(0,n+1):
        if(primes[i]):
            pr.append(i)
    return pr
def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
            p - 2, p)) % p
def denofactinverse(n,m):
    fac=1
    for i in range(1,n+1):
        fac=(fac*i)%m
    return (pow(fac,m-2,m))
def numofact(n,m):
    fac=1
    for i in range(1,n+1):
        fac=(fac*i)%m
    return(fac)
def sod(n):
    s=0
    while(n>0):
        s+=n%10
        n//=10
    return s
n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
val=[[] for i in range(0,200010)]
for i in range(0,n):
    cv=l[i]
    it=0
    while(l[i]>0):
        val[l[i]].append(it)
        it+=1
        l[i]//=2
ans=10**20
for i in range(0,len(val)):
    if(len(val[i])>=k):
        val[i].sort()
        ans=min(ans,sum(val[i][:k]))
print(ans)