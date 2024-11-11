import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left

from types import GeneratorType
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            self.os.write(self._fd, self.buffer.getvalue())
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
 
import time
start_time = time.time()

import collections as col
import math, string
from functools import reduce

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

MOD = 10**9+7

"""
We need to examine all edges, and any edges which go between different colours must be exclusively neighbours of the root
"""

def solve():
    N = getInt()
    graph = col.defaultdict(set)
    edges = []
    for n in range(N-1):
        U, V = getInts()
        if U > V: U, V = V, U
        U -= 1
        V -= 1
        graph[U].add(V)
        graph[V].add(U)
        edges.append((U,V))
    cols = getInts()
    diff_cols = col.defaultdict(int)
    total = 0
    for U, V in edges:
        if cols[U] != cols[V]:
            diff_cols[U] += 1
            diff_cols[V] += 1
            total += 1
    if total == 1:
        print("YES")
        print(edges[0][1]+1)
        return
    if not diff_cols:
        print("YES")
        print("1")
        return
    root = -10**9
    for key, val in diff_cols.items():
        if val > 1:
            if val != total:
                print("NO")
                return
            else:
                root = key+1
                break
    if root > 0:
        print("YES")
        print(root)
        return
    print("NO")
    return
    
#for _ in range(getInt()):    
solve()