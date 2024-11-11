# from collections import deque
import io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline # 神奇快读，无法运行调试
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


def input(): return sys.stdin.readline().rstrip("\r\n")


n, m = map(int, input().split())
# d = {}
inc = {
    # chr(97+i):0 for i in range(26)

}
l = [None for i in range(n*m)]

for i in range(n):
    t = int(input())
    # tmp = []
    for j in range(m):
        # tmp.append(input())
        ipt = input()
        l[t*m+j] = ipt
        if len(inc)==26:continue
        for q in ipt:
            inc.setdefault(q, 0)
    # d[t] = tmp
# l = []
# for i in range(n):
#     for j in d[i]:
#         l.append(j)

d = {}


# f = l[0][0]

def ae(u, v):
    t = d.setdefault(u, set())
    if v not in t:
        t.add(v)
        inc[v] = inc.get(v, 0) + 1


for p, i in enumerate(l[1:]):
    for j in range(min(len(l[p]), len(i))):
        if l[p][j] != i[j]:
            # if len(l[p])-1 != j:
                # ae(l[p][j],i[j])
            ae(i[j], l[p][j])
            break
        if len(i)-1==j and len(l[p])-1 > j:
            print("IMPOSSIBLE")
            exit(0)


ans = []
dq = []
# dq = deque()
ptr = 0


ninc = {}

for k, v in inc.items():
    if v == 0:
        dq.append(k)
    else:
        ninc[k] = v


# if ctr>1:
    # print("IMPOSSIBLE")
    # exit(0)

inc = ninc


while ptr != len(dq):
    fst = dq[ptr]
    ans.append(fst)

    for i in d.get(fst, []):
        inc[i] -= 1
        if inc[i] == 0:
            dq.append(i)
            inc.pop(i)

    # if ctr>1:
        # print("IMPOSSIBLE")
        # exit(0)
    ptr += 1

if len(inc):
    print("IMPOSSIBLE")
    exit(0)

print(*reversed(ans), sep='')
