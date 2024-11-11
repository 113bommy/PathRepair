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
def print_list(l):
    print(' '.join(map(str,l)))
# import sys
# sys.setrecursionlimit(5010)
from heapq import *
# from collections import deque as dq
# from math import ceil,floor,sqrt,pow
# import bisect as bs
# from collections import Counter
# from collections import defaultdict as dc 

data = [list(map(int,line.split())) for line in sys.stdin.readlines()]
# text = ['6 5 2',
# '1 2 5',
# '2 3 7',
# '2 4 4',
# '4 5 2',
# '4 6 8',
# '1 6',
# '5 3']
# data = [list(map(int,line.split())) for line in text]
n,m,k = data[0]
dist = [[1000000000]*(n+1) for _ in range(n+1)]
adj = [[] for _ in range(n+1)]
for u,v,w in data[1:m+1]:
    adj[u].append((v,w))
    adj[v].append((u,w))
for s in range(1,n+1):
    dist[s][s] = 0
    heap = [(0,s)]
    while heap:
        d,u = heappop(heap)
        if d!=dist[s][u]:
            continue
        else:
            for v,w in adj[u]:
                nd = d+w 
                if nd<dist[s][v]:
                    dist[s][v] = nd 
                    heappush(heap,(nd,v))
ans = float('inf')
for u,v,_ in data[1:m+1]:
    now = 0
    for a,b in data[m+1:]:
        now+=min(dist[a][b], dist[a][u] + dist[v][b], dist[a][v] + dist[u][b])
    ans = min(ans,now)
print(ans)

