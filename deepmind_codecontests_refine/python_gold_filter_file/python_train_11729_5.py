'''import os
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
input = lambda: sys.stdin.readline().rstrip("\r\n")'''
######################################################################
n=int(input())
s1=input()
s2=input()
s3=input()
x=len(s1)
a1,a2,a3=0,0,0
from collections import Counter
c1=Counter(s1)
c2=Counter(s2)
c3=Counter(s3)
i=65
while i<123:
    if c1[chr(i)]+n<=x:
        b=c1[chr(i)]+n
    else:
        c=c1[chr(i)]+n-x
        if n!=1:
            b=x
        else:
            b=x-1
    a1=max(a1,b)
    if c2[chr(i)]+n<=x:
        b=c2[chr(i)]+n
    else:
        c=c2[chr(i)]+n-x
        if n!=1:
            b=x
        else:
            b=x-1
    a2=max(a2,b)
    if c3[chr(i)]+n<=x:
        b=c3[chr(i)]+n
    else:
        c=c3[chr(i)]+n-x
        if n!=1:
            b=x
        else:
            b=x-1
    a3=max(a3,b)
    i+=1
    if i==92:
        i=97
l=[[a1,"Kuro"],[a2,"Shiro"],[a3,"Katie"]]
l.sort()
if l[-1][0]==l[-2][0]:
    print("Draw")
else:
    print(l[-1][1])
    
    
    
