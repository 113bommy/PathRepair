import os
import heapq
import sys
import math
import operator
from collections import defaultdict
from io import BytesIO, IOBase
sys.setrecursionlimit(10**5)

"""def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)"""

"""def pw(a,b):
    result=1
    while(b>0):
        if(b%2==1): result*=a
        a*=a
        b//=2
    return result"""

def inpt():
    return [int(k) for k in input().split()]


def fun(l,r,ct,ar,s):
    if (r-l==1):
        c1=chr(ct+97)
        c2=chr(ct+97+1)
        
        if((s[l-1]==c1 and s[r-1]==c2) or (s[l-1]==c2 and s[r-1]==c1)):
            return 0
        if((s[l-1]==c1 or s[r-1]==c1) or (s[l-1]==c2 or s[r-1]==c2)):
            return 1
        return 2

    mt=(l+r)//2

    ans1 =(mt-l)-(ar[ct][mt] - ar[ct][l-1])+1
    ans2=(r-mt)-(ar[ct][r] - ar[ct][mt])
    v1=fun(l,mt,ct+1,ar,s)
    v2=fun(mt+1,r,ct+1,ar,s)

    return min(ans1 + v2, ans2+v1)

def main():
    for _ in range(int(input())):
        n=int(input())
        s=input()
        if(n==1):
            if(s[0]=='a'):
                print(0)
            else:
                print(1)
            continue
        ar=[[0]*(n+1) for i in range(26)]
        for i in range(n):
            ar[ord(s[i])-97][i+1]+=1
            for j in range(26):
                ar[j][i+1]+=ar[j][i]
        print(fun(1,n,0,ar,s))










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
