import os
import sys
from io import BytesIO, IOBase
# region fastio

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

# ------------------------------

def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
def comb(n, m): return factorial(n) / (factorial(m) * factorial(n - m)) if n >= m else 0
def perm(n, m): return factorial(n) // (factorial(n - m)) if n >= m else 0
def mdis(x1, y1, x2, y2): return abs(x1 - x2) + abs(y1 - y2)
mod = 998244353
INF = float('inf')
from math import factorial
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush

# ------------------------------
# f = open('../input.txt')
# sys.stdin = f

def main():
    n, m = RL()
    arr = [0] + RLL()
    fris = [RLL() for _ in range(m)]

    rec = [0]*(n+1)
    recf = [[] for _ in range(n+1)]
    for i, (x, y) in enumerate(fris):
        rec[x]+=1
        rec[y]+=1
        recf[x].append(i)
        recf[y].append(i)

    q = deque()
    visc = [0]*(n+1)
    for i in range(1, n+1):
        if rec[i]<=arr[i]:
            q.append(i)
            visc[i] = 1

    vis = [0]*(m+1)
    res = []
    while q:
        gd = q.popleft()
        for who in recf[gd]:
            if vis[who]==1: continue
            vis[who] = 1
            res.append(who+1)
            x, y = fris[who]
            rec[x]-=1
            rec[y]-=1
            if visc[x]==0 and rec[x]<=arr[x]:
                q.append(x)
                visc[x] = 1
            if visc[y]==0 and rec[y]<=arr[y]:
                q.append(y)
                visc[y] = 1
    if len(res)==m:
        print("ALIVE")
        print(*res[::-1])
    else:
        print("DEAD")




if __name__ == "__main__":
    main()