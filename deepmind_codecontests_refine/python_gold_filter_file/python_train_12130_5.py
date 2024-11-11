"""
#If FastIO not needed, used this and don't forget to strip
#import sys, math
#input = sys.stdin.readline
"""
import os
import sys
from io import BytesIO, IOBase
import heapq as h 
from bisect import bisect_left, bisect_right

from types import GeneratorType
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        import os
        self.os = os
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = self.os.read(self._fd, max(self.os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
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
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

import collections as col

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

MOD = 10**9+7


"""
Either we destroy the first beacon and start by activating the second, or we activate the first
Suppose beacon i destroys k beacons to its left. Then beacon dp[i] = dp[i+k+1] + k
"""

def solve():
    N = getInt()
    beacons = []
    for n in range(N):
        A, B = getInts()
        beacons.append((A,B))
    beacons.sort()
    #we want to find the min number of beacons destroyed if the new one destroys 1, 2, 3, ..., n
    dp = [0]
    for j in range(1,N):
        #how many beacons to the left are within range?
        rng = beacons[j][0] - beacons[j][1]
        if beacons[j-1][0] < rng:
            dp.append(dp[-1])
            continue
        if beacons[0][0] >= rng:
            dp.append(j)
            continue
        right = j-1
        left = 0
        while right - left > 1:
            middle = (left+right)//2
            if beacons[middle][0] >= rng:
                right = middle
            else:
                left = middle
        tmp = dp[left]+j-left-1
        dp.append(tmp)
    ans = 10**9
    for j in range(N):
        ans = min(ans,dp[j]+N-j-1)
    return ans
    
    
    
#for _ in range(getInt()):
print(solve())