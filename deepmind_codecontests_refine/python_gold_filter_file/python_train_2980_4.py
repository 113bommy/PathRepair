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

def pre(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


def prod(a):
    ans = 1
    for each in a:
        ans = (ans * each)
    return ans

def lcm(a, b): return a * b // gcd(a, b)


def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y


k, a, b = map(int, input().split())
al = []
bo = []
for i in range(3):
    al += [list(map(int, input().split()))]
for i in range(3):
    bo += [list(map(int, input().split()))]

def format(a,b):
    return str(a)+","+str(b)

def point(a,b):
    return 1 if [a,b] in [[3,2],[2,1],[1,3]] else 0

oof = [format(a,b)]
st = set()
st.add(oof[0])
loop_after = 0
pts = [point(a,b)]
pts2 = [point(b,a)]

while True:
    a, b = al[a-1][b-1], bo[a-1][b-1]
    f = format(a,b)
    if f in st:
        loop_after = oof.index(f)
        break
    else:
        pts += [point(a, b)]
        pts2 += [point(b, a)]
        oof += [f]
        st.add(f)


if k <= loop_after:
    print(sum(pts[:k]), sum(pts2[:k]))
    quit()

p1, p2 = sum(pts[:loop_after]), sum(pts2[:loop_after])
pts = pts[loop_after:]
pts2 = pts2[loop_after:]
oof = oof[loop_after:]
k -= loop_after
s1, s2 = sum(pts), sum(pts2)
p1 += s1 * (k // len(pts))
p2 += s2 * (k // len(pts2))
k = k % len(pts)

print(p1 + sum(pts[:k]), p2+sum(pts2[:k]))