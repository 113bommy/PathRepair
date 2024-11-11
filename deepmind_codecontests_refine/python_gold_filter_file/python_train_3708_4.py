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
##########################################################
from collections import Counter
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
import heapq
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
# n = int(input())
# ls = list(map(int, input().split()))
# n, k = map(int, input().split())
# n =int(input())
#arr=[(i,x) for i,x in enum]
#arr.sort(key=lambda x:x[0])
#print(arr)
# e=list(map(int, input().split()))
from collections import Counter
#print("\n".join(ls))
#print(os.path.commonprefix(ls[0:2]))
#n=int(input())
from bisect import  bisect_right
#for _ in range(int(input())):
#n=int(input())
#arr = list(map(int, input().split()))
#for _ in range(int(input())):
#n, k = map(int, input().split())
import bisect
#n=int(input())
n, p,q,r = map(int, input().split())

arr = list(map(int, input().split()))


v1=[0]*n
v2=[0]*n
v1[0]=v2[0]=arr[0]
for i in range(1,n):
    v1[i]=min(arr[i],v1[i-1])
    v2[i] = max(arr[i], v2[i - 1])
#print(v2)
v3=[0]*n
v4=[0]*n
v3[-1]=v4[-1]=arr[-1]
for i in range(n-2,-1,-1):
    v3[i]=min(arr[i],v3[i+1])
    v4[i] = max(arr[i], v4[i + 1])
ans=-3*(10**18)

#print(v4)
for i in range(n):
    val=q*arr[i]
    if p<=0:
        val+=p*v1[i]
    else:
        val+=p*v2[i]
    if r <= 0:
        val += r * v3[i]
    else:
        val += r * v4[i]

    ans=max(ans,val)
print(ans)










