import os
import sys
from io import BytesIO, IOBase
import math
from decimal import *
from collections import defaultdict

getcontext().prec = 25

MOD = pow(10, 9) + 7
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

# n, k = map(int, input().split(" "))
#  = list(map(int, input().split(" ")))
# for _ in range(int(input())):


a = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
ans = []
for i in range(15):
    print(a[i])
    sys.stdout.flush()
    ans.append(input())

if ans.count("yes") > 1:
    print("composite")
elif ans.count('yes') == 1:
    yes = 1
    ind = 10

    for i in range(4):
        if ans[i] == "yes":
            ind = a[i]
            break
    j = 2
    while ind ** j < 101:
        print(ind ** j)
        sys.stdout.flush()
        if input() == "yes":
            yes += 1
            break
        j+=1
    if yes == 1:
        print('prime')
    else:
        print('composite')
else:
    print('prime')
