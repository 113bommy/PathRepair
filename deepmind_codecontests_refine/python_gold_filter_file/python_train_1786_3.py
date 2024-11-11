import os
import sys
from io import BytesIO, IOBase

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
#######################################
from collections import *
from operator import itemgetter , attrgetter
from decimal import *
import bisect
import math
import heapq as hq
MOD=10**9 +7



def pow(a,b,m):
    ans=1
    while b:
        if b&1:
            ans=(ans*a)%m
        b//=2
        a=(a*a)%m
    return ans
vis=[]
graph=[]
def dfs(v):
    if vis[v]: return 0
    vis[v]=True

    temp=0
    for vv in graph[v]:
        temp+=dfs(vv)
    return 1+temp
def ispalindrome(s):
    if s[:]==s[::-1]:
        return 1
    return 0
n,k=map(int,input().split())
l=list(map(int,input().split()))
h=[[10**6,0] for i in range(n+2)]
h[n+1]=[10**7,10**7]
h[0]=[10**7,10**7]
for i in range(k):
    h[l[i]][0]=min(h[l[i]][0],i+1)
    h[l[i]][1]=max(h[l[i]][1],i+1)
count=0

for i in range(1,n+1):
    if h[i]==[10**6,0]:
        count+=1

    if h[i+1][1]<h[i][0] or h[i+1][0]==10**6:
        count+=1
    if h[i-1][1]<h[i][0] or h[i-1][0]==10**6:
        count+=1

    
print(count)