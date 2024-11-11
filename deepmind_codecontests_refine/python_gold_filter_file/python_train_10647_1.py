# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase

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

# ------------------- fast io --------------------
from math import gcd, ceil

def prod(a, mod=10**9+7):
    ans = 1
    for each in a:
        ans = (ans * each) % mod
    return ans

def lcm(a, b): return a * b // gcd(a, b)

def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y

for _ in range(int(input()) if not True else 1):
    #n = int(input())
    n, k = map(int, input().split())
    #a, b = map(int, input().split())
    #c, d = map(int, input().split())
    #a = list(map(int, input().split()))
    #b = list(map(int, input().split()))
    #s = input()
    di = {}
    present = [False]*26
    for i in range(n):
        page = int(input())
        di[page] = []
        for __ in range(k):
            s = input()
            for i in s:
                present[ord(i)-97] = True
            di[page] += [s]
    words = []
    for u in sorted(k for k in di):
        words += di[u]

    graph = [set() for i in range(26)]
    pos = True
    for i in range(1, len(words)):
        j = 0
        while j < min(len(words[i]), len(words[i-1])):
            if words[i][j] == words[i-1][j]:
                j += 1
                continue
            l1, l2 = ord(words[i-1][j]) - 97, ord(words[i][j]) - 97
            if l1 in graph[l2]:
                pos = False
                break
            graph[l1].add(l2)
            break
        if len(words[i-1]) > len(words[i]) and words[i-1][:len(words[i])] == words[i]:
            print("IMPOSSIBLE")
            quit()
        if not pos:break
    if not pos:
        print("IMPOSSIBLE")
        quit()
    graph = [list(k) for k in graph]
    edges = [i for i in range(26) if present[i]]
    order = []
    vis = [False]*26
    while True:
        lo = len(order)
        for e in edges:
            if not graph[e] and e not in order:
                order += [e]
                vis[e] = True
        for i in range(26):
            for j in order:
                if j in graph[i]:
                    graph[i].remove(j)
        if lo == len(order):break
    order = order[::-1]
    if not order:
        print("IMPOSSIBLE")
        quit()
    pos = True
    for i in range(26):
        for j in graph[i]:
            if order.index(i) > order.index(j):
                pos = False
                break
        if not pos:break
    if not pos:print("IMPOSSIBLE")
    else:
        print("".join(chr(97+k) for k in order))