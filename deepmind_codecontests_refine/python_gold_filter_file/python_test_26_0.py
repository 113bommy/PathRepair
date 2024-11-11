import sys
import os
from math import ceil, floor, sqrt, gcd, factorial, log, log2
from io import BytesIO, IOBase
from collections import Counter
from itertools import permutations, combinations
from bisect import bisect
from functools import reduce

inf=int(10e9) + 7
BUFSIZE = 8192

inp = lambda: int(input())
mp = lambda: map(int, input().split())
lst = lambda: list(map(int, input().split()))

def factorialMod(n, modulus):
    ans=1
    if n <= modulus//2:
        #calculate the factorial normally (right argument of range() is exclusive)
        for i in range(1,n+1):
            ans = (ans * i) % modulus   
    else:
        #Fancypants method for large n
        for i in range(1,modulus-n):
            ans = (ans * i) % modulus
        ans = modinv(ans, modulus)

        #Since m is an odd-prime, (-1)^(m-n) = -1 if n is even, +1 if n is odd
        if n % 2 == 0:
            ans = -1*ans + modulus
    return ans % modulus


def main():
    for _ in range(inp()):
        n=inp()
        n=2*n
        f=3
        for i in range(4, n+1):
            f=(f*i)%1000000007
        
        
        # f=factorialMod(n, 1000000007)      
        # f=f//2
        if n==2:print(1)
        elif n==4:print(12)
        else:print(f%1000000007) 






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
