# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def check(mid,arr,m,n):
    ls = [[] for _ in range(1<<m)]
    for i in range(n):
        ans = 0
        for j in range(m):
            if arr[i][j] >= mid:
                ans += 1<<j
        ls[ans].append(i+1)
    for i in range(len(ls)):
        for j in range(len(ls)):
            if len(ls[i]) and len(ls[j]) and i|j == (1<<m)-1:
                return ls[i][0],ls[j][0]
    return 0

def main():
    n,m = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(n)]
    hi,lo,ind1 = 10**9,0,(1,1)
    while hi >= lo:
        mid = (hi+lo)//2
        ind = check(mid,arr,m,n)
        if ind:
            ind1 = ind
            lo = mid+1
        else:
            hi = mid-1
    print(*ind1)

#Fast IO Region
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

if __name__ == '__main__':
    main()