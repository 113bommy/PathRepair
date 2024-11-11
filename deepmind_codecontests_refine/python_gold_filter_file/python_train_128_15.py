# import math
# from collections import Counter
#from collections import defaultdict
#from collections import deque
# from bisect import bisect_left as bl, bisect_right as br
# from itertools import accumulate,permutations as perm,combinations as comb
# import heapq
# from functools import reduce
# from fractions import Fraction


def main():
    t = Iint()
    for _ in range(t):
        n, m = Imap()
        a = set(Imap())
        b = set(Imap())
        a = a & b
        if len(a) == 0:
            print("NO")
        else:
            for ai in a:
                print("YES")
                print(1, ai)
                break


# IO region
FIO = 1


def I(): return input()


def Iint(): return int(input())


def Ilist(): return list(map(int, input().split()))   # int list


def Imap(): return map(int, input().split())   # int map


def Plist(li, s=' '): print(s.join(map(str, li)))   # non string list


# /IO region
en = enumerate

if not FIO:
    if __name__ == '__main__':
        main()
        exit()
else:
    from io import BytesIO, IOBase
    import sys
    import os
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
# endregion


if __name__ == '__main__':
    main()
