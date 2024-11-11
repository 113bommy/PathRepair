#import sys, os.path
import os,sys
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

def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
from collections import*
from copy import*
import math
import string
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")

def charc(a,b):
    for i in range(3):
        if(alpha[i]!=a and alpha[i]!=b):
            return alpha[i]
def charc2(a):
    if(a=='A'):
        return 'B'
    else:
        return 'A'

n,k=map(int,input().split())
s=input()
res=[]
for i in range(n):
    res.append(s[i])
alpha=string.ascii_uppercase[:k]
c=0
if(n==1):
    print(0)
    print(s)
elif(k==2 or n==2):
    if(n%2==0):
        res1='AB'*(n//2)
        res2='BA'*(n//2)
    else:
        res1='AB'*(n//2)+'A'
        res2='BA'*(n//2)+'B'
    c1=0
    c2=0
    for i in range(n):
        if(s[i]!=res1[i]):
            c1+=1
        if(s[i]!=res2[i]):
            c2+=1
    final=min(c1,c2)
    print(final)
    if(final==c1):
        print(res1)
    else:
        print(res2)
else:
    for i in range(1,n-1):
        temp=res[i]
        if(res[i]!=res[i-1]):
            continue
        else:
            res[i]=charc(res[i+1],res[i-1])
            if(res[i]==None):
                res[i]=temp
            else:
                c+=1
    if(n>2):
        if(res[-2]==res[-1]):
            res[-1]=charc2(res[-2])
            c+=1
    print(c)
    print(''.join(res))




    

    
    