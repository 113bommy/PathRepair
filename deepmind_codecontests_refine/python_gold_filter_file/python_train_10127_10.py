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
from collections import Counter,defaultdict,deque
def int1():
    return int(input())
def map1():
    return map(int,input().split())
def list1():
    return list(map(int,input().split()))
mod=pow(10,9)+7
def solve():
    n,q=map1()
    l1=list1()
    sum1,i=0,0
    flag=0
    max1=0
    while(1):
        if(i==(n-1)):
            max1=max(max1,l1[i])
            #print(sum1,max1)
            print(max(n,max1+sum1))
            return
        if(l1[i]<l1[i+1]):
            i=i+1
            c1=l1[i-1]
            if(flag==1):
                sum1+=(c-c1)
                max1=0
            flag=0
            max1=max(max1,l1[i])
            #print(sum1,max1,i)
        else:
            if(flag==0):
                c=l1[i]
            flag=1
            i=i+1
            #print(sum1,max1)
for _ in range(int(input())):
    solve()