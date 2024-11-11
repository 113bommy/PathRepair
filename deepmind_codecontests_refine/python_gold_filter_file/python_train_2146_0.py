from collections import Counter
import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192
import math

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
def divs(n, start=2):
    divisors = []
    for i in range(start, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if n / i == i:
                divisors.append(i)
            else:
                divisors.extend([i, n // i])
    return divisors
##########################################################
#it=iter(t)
#if all(c in it for c in s):
#ls.sort(key=lambda x: (x[0], x[1]))
# ls.sort(key=lambda x: (x[0], x[1]))
import sys

inf = float("inf")
mod = 1000000007


def array(): return list(map(int, sys.stdin.readline().split()))


def intt(): return map(int, sys.stdin.readline().split())

from bisect import bisect_left

import sys



def fxn(st,en,ind,step):

    mid=st+(en-st)//2

    if ind<mid:

        return fxn(st,mid-1, ind, step-1)

    elif ind>mid:

        return fxn(mid+1, en, ind, step-1)

    else:

        return step

#n, k = map(int, sys.stdin.readline().split())
#arr = list(map(int, sys.stdin.readline().split()))
#arr=[(int(x),i) for i,x in enumerate(input().split())]
# ls=list(map(int,input().split()))
# for i in range(m):
#print(s[i],end="")
#n=int(sys.stdin.readline())
#arr=list(map(int,input().split()))
import sys
n=int(sys.stdin.readline())

arr=array()
if n==1:
    print(1)
    exit()
elif n==2:
    print(3 if arr[0]==arr[1] else 2)
    exit()

cnt=1
ans=0
for i in range(1,n):
    if arr[i]==arr[i-1]:
        cnt+=1
    else:
        ans+=cnt*(cnt+1)//2
        cnt=1
    if i==n-1 :
        if  arr[-1]==arr[-2]:
            ans+=cnt*(cnt+1)//2
        else:
            ans+=1


print(ans)