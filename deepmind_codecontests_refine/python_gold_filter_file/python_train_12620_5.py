import os
import sys
from io import BytesIO, IOBase
import math
from decimal import Decimal
from decimal import *
from collections import defaultdict, deque
import heapq
from decimal import Decimal
getcontext().prec = 25
abcd='abcdefghijklmnopqrstuvwxyz'
ABCD='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
months = {1:31, 2:28,3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
MOD = 1000000007
BUFSIZE = 8192
# sys.setrecursionlimit(10**6)
from bisect import bisect_left, bisect_right
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

# for _ in range(int(input())):
# map(int, input().split(" "))
# list(map(int, input().split(" ")))

n = int(input())
l = list(map(int, input().split(" ")))
ans = [0]
z = 0
for i in range(n):
    v = 0
    x = [l[i]]
    for j in range(i-1,-1,-1):
        x.append(min(x[-1],l[j]))
    x = x[::-1]
    for j in range(i+1, n):
        x.append(min(x[-1], l[j]))
    f = sum(x)
    if f>z:
        ans = x
        z = f
print(*ans)