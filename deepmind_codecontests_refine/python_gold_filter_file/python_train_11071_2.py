#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import*
from io import BytesIO, IOBase
def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
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
ALPHA='abcdefghijklmnopqrstuvwxyz'
M=1000000007
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]

#-------------------------code---------------------------#
# vsInput()


def Dist(x1,y1,x2,y2):
    return sqrt((x1-x2)**2 + (y2-y1)**2)

def Intersect(C1,C2):
    x1,y1,r1=C1
    x2,y2,r2=C2
    d=Dist(x1,y1,x2,y2)
    # print(C1,C2,d,r1,r2)
    return abs(r1-r2)<d<r1+r2

def inside(c1,c2):
    x1,y1,r1=c1
    x2,y2,r2=c2
    d=Dist(x1,y1,x2,y2)

    # print(d,r1,r2)

    return d+r1<=r2

def Check(circle,ring):
    inner=(ring[0],ring[1],ring[2])
    outer=(ring[0],ring[1],ring[3])
    
    if(inside(circle,inner) and not Intersect(circle,inner)): return True
    if(not inside(circle,outer) and not Intersect(circle,outer)): return True
    return False

Ring1=value()
Ring2=value()
x1,y1,r1,R1=Ring1
x2,y2,r2,R2=Ring2


ans=0

if(Check((x1,y1,r1),Ring2)):
    ans+=1
if(Check((x1,y1,R1),Ring2)):
    ans+=1
if(Check((x2,y2,r2),Ring1)):
    ans+=1
if(Check((x2,y2,R2),Ring1)):
    ans+=1

print(ans)




        
                
            









    
