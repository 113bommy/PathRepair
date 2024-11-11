# import itertools
# import bisect
# import heapq
# import math
from collections import defaultdict
import os
import sys
from io import BytesIO, IOBase

# sys.setrecursionlimit(10 ** 5)
ii = lambda: int(input())
lmii = lambda: list(map(int, input().split()))
slmii = lambda: sorted(map(int, input().split()))
li = lambda: list(input())
mii = lambda: map(int, input().split())
msi = lambda: map(str, input().split())


def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)


def lcm(a, b): return (a * b) // gcd(a, b)


def main():
    # for _ in " " * int(input()):
    n = ii()
    df = defaultdict(list)
    ds = defaultdict(list)
    dt = defaultdict(list)
    ind = defaultdict(list)
    for i in range(n):
        a, b, c = sorted(mii())
        ind[a, b, c].append(i + 1)
        df[(a, b)].append(c)
        ds[(b, c)].append(a)
        dt[(a, c)].append(b)
    vol = 0
    f = 1
    ci = -1
    ff = -1
    ss = -1
    for i in df:
        df[i].sort(reverse=True)
        if len(df[i]) == 1:
            if min(i[0],i[1],df[i][0]) >= vol:
                vol = min(i[0],i[1],df[i][0])
                f = 1
                ci = ind[i[0], i[1], df[i][0]][-1]
        else:
            if min(i[0],i[1],(df[i][-1] + df[i][-2])) >= vol:
                vol = min(i[0],i[1],(df[i][-1] + df[i][-2]))
                f = 2
                ff = ind[i[0], i[1], df[i][-1]][-1]
                ss = ind[i[0], i[1], df[i][-2]][-1]
                if ff == ss:
                    ff = ind[i[0], i[1], df[i][-1]][-1]
                    ss = ind[i[0], i[1], df[i][-2]][-2]

    for i in ds:
        ds[i].sort()
        if len(ds[i]) == 1:
            if min(i[0],i[1],ds[i][0]) >= vol:
                vol = min(i[0],i[1],ds[i][0])
                f = 1
                ci = ind[ds[i][0], i[0], i[1]][-1]
        else:
            if min(i[0],i[1],(ds[i][-1] + ds[i][-2])) >= vol:
                vol = min(i[0],i[1],(ds[i][-1] + ds[i][-2]))
                f = 2
                ff = ind[ds[i][-1], i[0], i[1]][-1]
                ss = ind[ds[i][-2], i[0], i[1]][-1]
                if ff == ss:
                    ff = ind[ds[i][-1], i[0], i[1]][-1]
                    ss = ind[ds[i][-2], i[0], i[1]][-2]

    for i in dt:
        dt[i].sort()
        if len(dt[i]) == 1:
            if min(i[0] , i[1] , dt[i][0]) >= vol:
                vol = min(i[0] , i[1] , dt[i][0])
                f = 1
                ci = ind[i[0], dt[i][0], i[1]][-1]
        else:
            if min(i[0] , i[1] , (dt[i][-1] + dt[i][-2])) >= vol:
                vol = min(i[0] , i[1] , (dt[i][-1] + dt[i][-2]))
                f = 2
                ff = ind[i[0], dt[i][-1], i[1]][-1]
                ss = ind[i[0], dt[i][-2], i[1]][-1]
                if ff == ss:
                    ff = ind[i[0], dt[i][-1], i[1]][-1]
                    ss = ind[i[0], dt[i][-2], i[1]][-2]
    print(f)
    if f == 2:
        print(ff, ss)
    else:
        print(ci)


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
