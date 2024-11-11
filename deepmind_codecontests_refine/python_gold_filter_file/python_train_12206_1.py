import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType
from bisect import *
from collections import defaultdict, deque, Counter
import math
import string
from heapq import *
from operator import add
from itertools import accumulate

BUFSIZE = 8192
sys.setrecursionlimit(10 ** 5)


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
            b = self.os.read(self._fd, max(
                self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(
                self.os.fstat(self._fd).st_size, BUFSIZE))
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
def input(): return sys.stdin.readline().rstrip("\r\n")


inf = float("inf")
def en(x): return list(enumerate(x))
def ceil_(a, b): return (a + b - 1) // b


def ii(): return int(input())
def r(): return map(int, input().split())
def rr(): return list(r())


# --------------------------


n = ii()
arr = rr()
x = sum(arr)
ans = []
for j, i in enumerate(arr):
    if (x-i)/(n-1) == i:
        ans += j + 1,
        
print(len(ans))

print(*ans)