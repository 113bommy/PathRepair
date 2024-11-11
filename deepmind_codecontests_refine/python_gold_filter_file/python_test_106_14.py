# Sujith
from sys import stdin,stdout,setrecursionlimit
from io import BytesIO, IOBase
# from heapq import heappush as push,heappop as hp,heapify as h
from math import gcd,floor,sqrt,ceil
# from collections import Counter,deque as dq,defaultdict as dd
# from itertools import accumulate as acc,permutations as perm
# from bisect import bisect_left as bl,bisect_right as br,bisect as bis

setrecursionlimit(10000)

class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
        self.BUFSIZE = 8192

    def read(self):
        while True:
            a = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            if not a:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(a), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            a = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, self.BUFSIZE))
            self.newlines = a.count(b"\n") + (not a)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(a), self.buffer.seek(ptr)
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


stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)
input = lambda: stdin.readline().rstrip("\r\n")

# inf = float('inf')
# ninf = float('-inf')
# abc = 'abcdefghijklmnopqrstuvwxyz'
inp = lambda: int(input())
st = lambda: input().strip()
jn = lambda x,l: x.join(map(str,l))
int_arr = lambda : list(map(int,input().strip().split()))
str_arr = lambda :list(map(str,input().split()))
get_str = lambda : map(str,input().strip().split())
get_int = lambda: map(int,input().strip().split())
get_float = lambda : map(float,input().strip().split())

mod = 1000000007

#main()
for _ in range(inp()):
    n = inp()
    lst = [i for i in range(2,n + 2)]
    print(*lst)