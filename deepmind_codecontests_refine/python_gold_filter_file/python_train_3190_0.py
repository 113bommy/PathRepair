import itertools
import bisect
import collections

import math
import sys

from collections import *

import os
import sys
from io import BytesIO, IOBase

ii = lambda: int(input())
lmii = lambda: list(map(int, input().split()))
li = lambda: list(input())
mii = lambda: map(int, input().split())
msi = lambda: map(str, input().split())


def main():
    lst = []
    for i in range(11):
        lst.append(li())
    x, y = mii()
    s1, s2, s3, s4, s5, s6, s7, s8, s9 = "", "", "", "", "", "", "", "", ""
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if i <= 2 and j <= 2:
                s1 += lst[i][j]
            if 4 <= i <= 6 and j <= 2:
                s4 += lst[i][j]
            if 8 <= i <= 10 and j <= 2:
                s7 += lst[i][j]
            if i <= 2 and 4 <= j <= 6:
                s2 += lst[i][j]
            if 4 <= i <= 6 and 4 <= j <= 6:
                s5 += lst[i][j]
            if 8 <= i <= 10 and 4 <= j <= 6:
                s8 += lst[i][j]
            if i <= 2 and 8 <= j <= 10:
                s3 += lst[i][j]
            if 4 <= i <= 6 and 8 <= j <= 10:
                s6 += lst[i][j]
            if 8 <= i <= 10 and 8 <= j <= 10:
                s9 += lst[i][j]

    if x >= 1 and (x - 1) % 3 == 0 and y >= 1 and (y - 1) % 3 == 0:
        if s1.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if i <= 2 and j <= 2 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif x >= 1 and (x - 1) % 3 == 0 and y >= 2 and (y - 2) % 3 == 0:
        if s2.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if i <= 2 and 4 <= j <= 6 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif x >= 1 and (x - 1) % 3 == 0 and y % 3 == 0:
        if s3.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if i <= 2 and 8 <= j <= 10 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif x >= 2 and (x - 2) % 3 == 0 and y >= 1 and (y - 1) % 3 == 0:
        if s4.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 4 <= i <= 6 and j <= 2 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif x >= 2 and (x - 2) % 3 == 0 and y >= 2 and (y - 2) % 3 == 0:
        if s5.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 4 <= i <= 6 and 4 <= j <= 6 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif x >= 2 and (x - 2) % 3 == 0 and (y - 0) % 3 == 0:
        if s6.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 4 <= i <= 6 and 8 <= j <= 10 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif (x - 0) % 3 == 0 and y >= 1 and (y - 1) % 3 == 0:
        if s7.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 8 <= i <= 10 and j <= 2 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    elif (x - 0) % 3 == 0 and y >= 2 and (y - 2) % 3 == 0:
        if s8.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 8 <= i <= 10 and 4 <= j <= 6 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    else:
        if s9.count("."):
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if 8 <= i <= 10 and 8 <= j <= 10 and lst[i][j] == ".":
                        lst[i][j] = "!"
        else:
            for i in range(len(lst)):
                for j in range(len(lst[i])):
                    if lst[i][j] == ".":
                        lst[i][j] = "!"
    for i in range(len(lst)):
        print("".join(lst[i]))
    return


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

# endregion

if __name__ == "__main__":
    main()
