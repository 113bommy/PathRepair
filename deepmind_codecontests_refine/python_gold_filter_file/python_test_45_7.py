# template taken from https://github.com/cheran-senthil/PyRival/blob/master/templates/template.py

import os
import sys
from io import BytesIO, IOBase
import math
from heapq import heappop, heappush, heapify
from collections import deque

def read():
    sys.stdin  = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w') 

# ------------------------------------------- Algos --------------------------------------------------------

def lower_bound(arr, n, k):
    start = 0
    end = n-1
    while start <= end:
        mid = (start+end)//2
        if arr[mid] == k:
            return mid
        elif arr[mid] > k:
            if mid > 0:
                if arr[mid-1] < k:
                    return (mid-1)
            else:
                return -1
        else:
            if mid < (n-1):
                if arr[mid+1] > k:
                    return mid
            else:
                return mid
def upper_bound(arr, n, k):
    start = 0
    end = n-1
    while start <= end:
        mid = (start+end)//2
        if arr[mid] == k:
            return mid
        elif arr[mid] > k:
            if mid > 0:
                if arr[mid-1] < k:
                    return (mid)
            else:
                return mid
        else:
            if mid < (n-1):
                if arr[mid+1] > k:
                    return (mid+1)
            else:
                return -1
def gcd(a,b):
    if a == 0:
        return b
    return gcd(b % a, a)
def lcm(a,b):
    return (a // gcd(a,b))* b

# -------------------------------------------------- code -------------------------------------------------
def helper():
    pass

def main():
 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))

        ans = 1
        flag = True
        for i in range(n):
            if i >= 1:
                if arr[i-1] == 0 and arr[i] == 0:
                    flag = False
                    break

                elif arr[i-1] == 1 and arr[i] == 1:
                    ans += 5

                elif arr[i-1] == 0 and arr[i] == 1:
                    ans += 1


            else:
                if arr[i] == 1:
                    ans += 1

        if flag:
            print(ans)

        else:
            print(-1)


# ---------------------------------------------- region fastio ---------------------------------------------
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

# -------------------------------------------------- end region ---------------------------------------------

if __name__ == "__main__":
    #read()
    main()