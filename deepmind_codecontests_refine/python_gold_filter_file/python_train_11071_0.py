import os
import sys
from io import BytesIO, IOBase
from collections import Counter

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


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


mod = int(1e9) + 7


def lcm(a, b):
    return (a * b) / gcd(a, b)


def power(k, n):
    if n == 0:
        return 1
    if n % 2:
        return (power(k, n - 1) * k) % mod
    t = power(k, n // 2)
    return (t * t) % mod



def intersect(a, b):
    d2=(a[0]-b[0])**2+(a[1]-b[1])**2
    r1r22=(a[2]+b[2])**2
    dr1r22=(a[2]-b[2])**2
    # print(a, b)
    # print(dr1r22, d2, r1r22)
    return dr1r22<d2<r1r22

def lies(a, b, c):
    d2=(a[0]-b[0])**2+(a[1]-b[1])**2
    # if a[2]>b[2]:
    #     return 0
    # if a[2]>c[2]:
    #     return 1
    return (max(0,b[2]-a[2]))**2<d2<=(max(0,c[2]-a[2]))**2




def main():
    a = []
    x, y, r, R = map(int, input().split())
    a.append([x, y, r])
    a.append([x, y, R])
    x, y, r, R = map(int, input().split())
    a.append([x, y, r])
    a.append([x, y, R])

    ans=0
    for i in range(4):
        f=0
        for j in range(4):
            if i!=j and intersect(a[i], a[j]):
                f=1
        #print(i, f)
        if i<2:
            if lies(a[i], a[2], a[3]):
                f=1
        else:
            if lies(a[i], a[0], a[1]):
                f=1
        #print(i, f)
        if f==0:
            ans+=1
    print(ans)






    return


if __name__ == "__main__":
    main()
