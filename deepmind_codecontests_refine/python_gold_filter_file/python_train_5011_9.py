from sys import stdout, stdin, setrecursionlimit
from io import BytesIO, IOBase
from collections import *
from itertools import *
from random import *
from bisect import *
from string import *
from queue import *
from heapq import *
from math import *
from re import *
from os import *

####################################---fast-input-output----#########################################


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = read(self._fd, max(fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)
def input(): return stdin.readline().strip()
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = fast, lambda: (map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9 + 7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))
def output(answer, end='\n'): stdout.write(str(answer) + end)


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


#################################################---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some-one , Then you probably don't know him !

    --Try & again try

"""
##################################################---START-CODING---###############################################


n = int(z())
arr = list(fast())
ans=0
for i in range(1,n-1):
    a=arr[i-1]
    b=arr[i]
    c=arr[i+1]
    if a==b:
        if b=='R' and c!="B":
            arr[i]="B"

        elif b=='R' and c!="G":
            arr[i]="G"

        elif b=='G' and c!="B":
            arr[i]="B"

        elif b=='G' and c!="R":
            arr[i]="R"
        elif b=="B" and c!='R':
            arr[i]='R'
        elif b=='B' and c!='G':
            arr[i]='G'
        ans+=1
if n==1:
    print(0)
    print(*arr)
    exit()
a=arr[-2]
b=arr[-1]
if a==b:
    if a=='R':
        arr[-1]='G'
    if a=='G':
        arr[-1]='R'
    if a=='B':
        arr[-1]='G'
    ans+=1
print(ans)
print(''.join(arr))
            
