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

testcases=int(input())

for j in range(testcases):
    list1=[ord(k) for k in input()]
    list1.sort()
    real=[list1[0]]
    reps=[1]
    for s in range(1,len(list1)):
        if list1[s]==real[-1]:
            reps[len(real)-1]+=1
        else:
            real.append(list1[s])
            reps.append(1)
    m=int(input())
    vals=list(map(int,input().split()))
    outy=[0]*len(vals)
    n=len(vals)
    for s in range(len(real)):
        zeros=[]
        for b in range(n):
            if vals[b]==0:
                zeros.append(b)
                vals[b]="x"
        maxsofar=-1
        for b in range(len(real)-1,-1,-1):
            if reps[b]>=len(zeros):
                maxsofar=real.pop()
                reps.pop()
                break
            else:
                real.pop()
                reps.pop()
        if maxsofar>-1:
            for b in range(len(zeros)):
                outy[zeros[b]]=maxsofar
        for b in range(len(zeros)):
            ind=zeros[b]
            for i in range(n):
                if vals[i]!="x":
                    if vals[i]>0:
                        vals[i]-=abs(ind-i)
    outy=[chr(k) for k in outy]
    print("".join(outy))