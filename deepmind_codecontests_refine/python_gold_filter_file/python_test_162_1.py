from __future__ import print_function
from math import *
from collections import deque
import os
import sys
from io import BytesIO, IOBase
#import time
 
def main():
    pass
 
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
#sys.stdin, sys.stdout =open("test.txt","r"),open("result.txt","w")
#ini=time.time()
input = lambda: sys.stdin.readline().rstrip("\r\n")
mod=10**9+7
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split()))
for _ in range(inp()):
    n=inp()
    l=inlt()
    s=sum(l)
    a=s//n
    ans=min(l)
    l1=l[:]
    low=0
    high=10**9+7
    while low<=high:
        #print(low,high)
        temp=[0]*n
        l=l1[:]
        a=(high+low)//2
        for i in range(n-1,1,-1):
            if temp[i]+l[i]>=a:
                allo=min(l[i],temp[i]+l[i]-a)
                #print(allo)
                d=allo//3
                temp[i-1]+=d
                temp[i-2]+=2*d
                l[i]-=3*d
                #print(temp)
                #print(l)
        for i in range(n):
            l[i]=l[i]+temp[i]
        #print(l)
        m=min(l)
        ans=max(ans,m)
        if m>=a:
            low=a+1
        else:
            high=a-1
    for i in range(n):
        l[i]=l[i]+temp[i]
    print(ans)