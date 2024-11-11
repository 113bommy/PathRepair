# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def mat_multiply(a,b,mod):
    x = len(a)
    res = [[0]*x for _ in range(x)]
    for i in range(x):
        for j in range(x):
            for k in range(x):
                res[i][j] += a[i][k]*b[k][j]
                res[i][j] %= mod
    return res

def mat_expo(a,n,mod):
    iden = [[0]*len(a) for _ in range(len(a))]
    for i in range(len(a)):
        iden[i][i] = 1
    while n:
        if n%2:
            iden = mat_multiply(iden,a,mod)
        a = mat_multiply(a,a,mod)
        n //= 2
    return iden

def main():
    n,k,l,m = map(int,input().split())
    mat = [[0,1],[1,1]]
    xx = mat_expo(mat,n-1,m)
    not_set = (xx[0][0]+xx[0][1]+xx[1][0]+xx[1][1])%m
    se = (pow(2,n,m)-not_set)%m
    mask = 1
    ans = 1%m
    if k.bit_length() >= l+1:
        print(0)
        return
    for _ in range(l):
        if mask&k:
            ans = (ans*se)%m
        else:
            ans = (ans*not_set)%m
        mask <<= 1
    print(ans)

# Fast IO Region
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