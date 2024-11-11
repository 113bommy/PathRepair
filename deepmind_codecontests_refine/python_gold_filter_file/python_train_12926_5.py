# ------------------- fast io --------------------
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
 
# ------------------- fast io --------------------
import math
def solution( A, k):
    N = len(A)
    if (N < k or N < 1 or k < 1):
        return 0
    if (N == k):
        return 1
    v1 = [0]*(N)
    v2 = [0]*N
    v3 = [0]*N
    v2[N - 1] = 1
    v3[A[N - 1] - 1] = 1
    for i in range(N - 2,-1,-1):
        v2[i] = v2[i + 1]
        if (v3[A[i] - 1] == 0):
            v2[i] += 1
            v3[A[i] - 1] = 1
    for j in range( 1, k) :
        v3 = [0]*N
        v1[N - 1] = 0
        for i in range( N - 2, -1, -1) :
            v1[i] = v1[i + 1]
            v1[i] = v1[i] + v2[i + 1]
            v1[i] = v1[i] - v3[A[i] - 1]
            v3[A[i] - 1] = v2[i + 1]
        for i in range(len(v1)):
            v2[i] = v1[i]
    return v2[0]
def solve(a, n, k):
    v = a
    return( solution(v, k))
from collections import defaultdict
#calculate the number of substrings of each length
n,k=map(int,input().split())
string1=[ord(k) for k in input()];ans=[]
vv=set(string1);vv=list(vv);vv.sort()
dmap=defaultdict(int)
for s in range(len(vv)):
    dmap[vv[s]]=s+1
string1=[dmap[k] for k in string1]
for s in range(1,n+1):
    ans.append(solve(string1,n,s))
ret=0
for s in range(n-1,-1,-1):
    if k>=ans[s]:
        k-=ans[s];ret+=(n-(s+1))*(ans[s])
    else:
        ret+=(n-(s+1))*k
        k=0
        break
if k==0:
    print(ret)
elif k==1:
    print(ret+n)
else:
    print(-1)