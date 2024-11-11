
from bisect import bisect,bisect_left
'''
from collections import *
from math import gcd,ceil,sqrt,floor,inf
from heapq import *
from itertools import *
from operator import add,mul,sub,xor,truediv,floordiv
from functools import *'''

#------------------------------------------------------------------------
import os
import sys

from io import BytesIO, IOBase
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
 

#------------------------------------------------------------------------
def RL(): return map(int, sys.stdin.readline().split())
def RLL(): return list(map(int, sys.stdin.readline().split()))
def N(): return int(input())
def A(n):return [0]*n
def AI(n,x): return [x]*n
def A2(n,m): return [[0]*m for i in range(n)]
def G(n): return [[] for i in range(n)]
def GP(it): return [[ch,len(list(g))] for ch,g in groupby(it)]
#------------------------------------------------------------------------



from random import random    
t=1
for i in range(t):
    n,q=RL()
    a=RLL()
    g=G(n+1)
    for i in range(n):
        g[a[i]].append(i)
    for i in range(q):
        l,r=RL()
        l-=1
        r-=1
        c=0
        s=set()
        h=(r-l+2)//2
        lt=r-l+1
        ans=1
        for i in range(20):
            x=a[int(random()*(lt))+l]
            if x in s:
                continue
            s.add(x)
            lind=bisect_left(g[x],l)
            if lind+h<len(g[x]) and g[x][lind+h]<=r:
                rind=bisect(g[x],r)-1
                ans=(rind-lind+1)*2-lt
                break
        print(ans)
    


