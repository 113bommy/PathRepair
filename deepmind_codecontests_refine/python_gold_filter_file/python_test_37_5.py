import os
import sys
from io import BytesIO, IOBase

_str = str
str = lambda x=b"": x if type(x) is bytes else _str(x).encode()

BUFSIZE = 8192


def sigma1(a):
    return sum(a)
def sigma2(a):
    return sum([i*i for i in a])
def sigma3(a):
    return sum([i*i*i for i in a])
def prodofpairs(a):
    return (sigma1(a)**2-sigma2(a))//2
def prodoftriplets(a):
    return (sigma1(a)**3-3*sigma1(a)*sigma2(a)+2*sigma3(a))//6
from collections import Counter,defaultdict
from math import gcd
from collections import deque
def bfs(graph, start=0):
    used = [False] * len(graph)
    used[start] = True
    q = [start]
    for v in q:
        for w in graph[v]:
            if not used[w]:
                used[w] = True
                q.append(w)


def layers(graph, start=0):
    used = [False] * len(graph)
    used[start] = True
    q, ret = [start], []
    level=[0]*len(graph)
    while q:
        nq = []
        ret.append(q)
        for v in q:
            for w in graph[v]:
                if not used[w]:
                    used[w] = True
                    nq.append(w)
                    level[w]=1+level[v]
        q = nq
    return level

import math
 
# function to find GCD of sub sequence
# of size k with max GCD in the array
def findMaxGCD(arr, n, k):
    high = max(arr)
    divisors = [0] * (high + 1)
    for i in range(n) :
        for j in range(1, int(math.sqrt(arr[i])) + 1):
            if (arr[i] % j == 0) :
                divisors[j] += 1
                if (j != arr[i] // j):
                    divisors[arr[i] // j] += 1
    for i in range(high, 0, -1):
        if (divisors[i] >= k):
            return i
def xdist(a,b):
    if(b[0]>=a[0]>=b[2] or b[0]<=a[0]<=b[2] ):
        return 0
    return min(abs(a[0]-b[0]),abs(a[0]-b[2]))
def ydist(a,b):
    if(b[1]>=a[1]>=b[3] or b[1]<=a[1]<=b[3] ):
        return 0
    return min(abs(a[1]-b[1]),abs(a[1]-b[3]))
def countdistx(i,j,k,obj):
    m=0
    for i1 in range(k):
        m+=xdist([i,j],obj[i1])
    return m
def countdisty(i,j,k,obj):
    m=0
    for i1 in range(k):
        m+=ydist([i,j],obj[i1])
    return m
from bisect import bisect_left
def dp(i,n,cost,a):
    if(cost==0):
        return 0
    if(cost<0):
        return float("Inf")
    l=[float("Inf")]
    for j in range(i,n+1):
        k=bisect_left(a,a[j]+cost,j)
        if(k<=n and a[k]==a[j]+cost):
            l.append(k-j)
    return min(l)
def isp(x):
    for i in range(2,int(math.sqrt(x))+1):
        if(x%i==0):
            return False
    return True
def main():
    mod=10**9+7
    for _ in range(int(input())):
        n,m=map(int,input().split())
        res=[list(map(int,input().split())) for i in range(m)]
        s=set(list(range(1,n+1)))
        for i,j,k in res:
            s.discard(j)
        for i in s:
            for j in range(1,n+1):
                if(i!=j):
                    print(i,j)
            break
            




        





        


        

main()

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




