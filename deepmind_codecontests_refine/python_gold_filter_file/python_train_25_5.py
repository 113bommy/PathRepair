''' ===============================
    -- @uthor : Kaleab Asfaw       
    -- Handle : kaleabasfaw2010    
    -- Bio    : High-School Student
    ==============================='''

# Fast IO
import sys
import os
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file): self._fd = file.fileno(); self.buffer = BytesIO(); self.writable = "x" in file.mode or "r" not in file.mode; self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b: break
            ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0; return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE)); self.newlines = b.count(b"\n") + (not b); ptr = self.buffer.tell(); self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1; return self.buffer.readline()
    def flush(self):
        if self.writable: os.write(self._fd, self.buffer.getvalue()); self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file): self.buffer = FastIO(file); self.flush = self.buffer.flush; self.writable = self.buffer.writable; self.write = lambda s: self.buffer.write(s.encode("ascii")); self.read = lambda: self.buffer.read().decode("ascii"); self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout); input = lambda: sys.stdin.readline().rstrip("\r\n")
# Others
# from math import floor, ceil, gcd
# from decimal import Decimal as d
mod = 10**9+7
def lcm(x, y): return (x * y) / (gcd(x, y))
def fact(x, mod=mod):
    ans = 1
    for i in range(1, x+1): ans = (ans * i) % mod
    return ans
def arr2D(n, m, default=0): return [[default for j in range(m)] for i in range(n)]
def arr3D(n, m, r, default=0): return [[[default for k in range(r)] for j in range(m)] for i in range(n)]
def sortDictV(x): return {k: v for k, v in sorted(x.items(), key = lambda item : item[1])}

def solve(n, lst):
    ans = []
    if lst[0][1] == "1":
        if lst[1][0] == "0":
            ans.append([2, 1])
        if lst[n-1][n-2] == "1":
            ans.append([n, n-1])
        if lst[n-2][n-1] == "1":
            ans.append([n-1, n])
    else:
        if lst[1][0] == "1":
            ans.append([2, 1])
        if lst[n-1][n-2] == "0":
            ans.append([n, n-1])
        if lst[n-2][n-1] == "0":
            ans.append([n-1, n])
    if len(ans) > 2:
        print(1)
        print(1, 2)
    else:
        print(len(ans))
        for i in ans:
            print(i[0], i[1])



for _ in range(int(input())): # Multicase
    n = int(input())
    lst = []
    for i in range(n):
        lst.append(list(input()))
    solve(n, lst)