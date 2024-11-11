import time

#start_time = time.time()
#def TIME_(): print(time.time()-start_time)

import os, sys
from io import BytesIO, IOBase
from types import GeneratorType
from bisect import bisect_left, bisect_right
from collections import defaultdict as dd, deque as dq, Counter as dc
import math, string, heapq as h
BUFSIZE = 8192

class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
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

def getInt(): return int(input())
def getStrs(): return input().split()
def getInts(): return list(map(int,input().split()))
def getStr(): return input()
def listStr(): return list(input())
def getMat(n): return [getInts() for _ in range(n)]
def getBin(): return list(map(int,list(input())))
def isInt(s): return '0' <= s[0] <= '9'
def ceil_(a,b): return a//b + (a%b > 0)

MOD = 998244353

"""

"""

primes = [2,3,5,7,11,13,17,19]

def solve():
    N, M = getInts()
    dist = [getInts() for _ in range(N)]
    num = 0
    for j in range(M):
        tmp = [dist[i][j] for i in range(N)]
        tmp.sort()
        mult = 1
        for i in range(N):
            mult *= max(tmp[i]-1-i,0)
        num += mult
    denom = 1
    for i in range(2,N+1): denom *= i
    num = denom*M - num
    for i in primes:
        if i > N: break
        while num % i == 0 and denom % i == 0:
            num //= i
            denom //= i
    num %= MOD
    denom %= MOD
    return (num * (pow(denom,MOD-2,MOD)))%MOD
    
#for _ in range(getInt()):
print(solve())
    #solve()

#TIME_()