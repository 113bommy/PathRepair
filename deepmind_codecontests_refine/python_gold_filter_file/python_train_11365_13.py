import itertools
import bisect
import math
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
    # for _ in " " * int(input()):
    n = ii()
    s = li()
    if n%2==0:
        if s[n//2] != "0":
            print(int("".join(s[:n//2]))+int("".join(s[n//2:])))
        else:
            ind = n//2
            high = -19999999999
            for i in range(ind,n):
                if s[i] != "0":
                    high = i
                    break
            low = -199999999999
            for i in range(ind,-1,-1):
                if s[i] != "0":
                    low = i
                    break
            if low == 0:
                print(int("".join(s[:high])) + int("".join(s[high:])))
            elif high == -19999999999:
                print(int("".join(s[:low]))+int("".join(s[low:])))
            else:
                print(min(int("".join(s[:low]))+int("".join(s[low:])), int("".join(s[:high]))+int("".join(s[high:]))))
    else:
        if s[n//2] != "0":
            print(min(int("".join(s[:n//2]))+int("".join(s[n//2:])), int("".join(s[:(n+1)//2]))+int("".join(s[(n+1)//2:]))))
        else:
            ind = n // 2
            high = -19999999999
            for i in range(ind, n):
                if s[i] != "0":
                    high = i
                    break
            low = -199999999999
            for i in range(ind, -1, -1):
                if s[i] != "0":
                    low = i
                    break
            if low == 0:
                print(int("".join(s[:high])) + int("".join(s[high:])))
            elif high == -19999999999:
                print(int("".join(s[:low])) + int("".join(s[low:])))
            else:
                print(min(int("".join(s[:low])) + int("".join(s[low:])), int("".join(s[:high])) + int("".join(s[high:]))))
    pass


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

if __name__ == "__main__":
    main()
