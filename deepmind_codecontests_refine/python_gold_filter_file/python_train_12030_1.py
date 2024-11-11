"""
#If FastIO not needed, used this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""

import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left, bisect_right

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

from collections import defaultdict as dd, deque as dq
import math, string

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
We need to maintain a set of unread notifications from which we can remove the first max(ti), and also the first xi for each application
[3,4,4,1,1,1,2,2,1,3,3,2,4,4,1,2,3,2,4,4]

N applications. At any given time the number of unread notifications is the sum of the number of unread notifications for each application, which lends itself to a Fenwick Tree
But how do we maintain the order?

As we delete the first N elements, we can also subtract one from the rolling sum and from the element total.
As we clear an element of type X, we can subtract that many from the rolling total

"""

def solve():
    N, Q = getInts()
    order = dq([])
    cur_total = 0
    cur_del = -1
    els = [0]*(N+1)
    del_up_to = [-1]*(N+1)
    for q in range(Q):
        T, X = getInts()
        if T == 1:
            order.append(X)
            els[X] += 1
            cur_total += 1
            print(cur_total)
        elif T == 2:
            cur_total -= els[X]
            els[X] = 0
            del_up_to[X] = max(len(order)-1,del_up_to[X])
            print(cur_total)
        elif T == 3:
            if X-1 > cur_del:
                for i in range(cur_del+1,X):
                    if del_up_to[order[i]] < i:
                        cur_total -= 1
                        del_up_to[order[i]] = i
                        els[order[i]] -= 1
                #print(order)
                #print(els)
                #print(del_up_to)
                cur_del = X-1
            print(cur_total)
    return
    
#for _ in range(getInt()):
solve()
