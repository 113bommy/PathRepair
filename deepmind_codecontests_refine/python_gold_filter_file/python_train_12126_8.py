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
input = lambda: sys.stdin.readline().rstrip("\r\n")
##########################################################
#from fractions import Fraction
# import math
import sys
import math
from math import gcd
# from collections import deque
# from collections import Counter
#import sys
#ys.setrecursionlimit(10 ** 6)
#for _ in range(int(input())):
#n, k = map(int, input().split())
#from bisect import bisect_right
#n =int(input())
#for _ in range(int(input())):
import bisect
#for _ in range(int(input())):
#n, m =map(int,input().split())
#for _ in (int(input())):
#open("output.txt","w").write(s)
#n=int(open("input.txt").read())
#open("output.txt","w").write(s)
#arr=list(map(int,input().split()))
# n =int(input())
a=[0]*26
'''for _ in range(int(input())):
    n = int(input())

    arr = list(map(int, input().split()))'''
from collections import deque
#n, m =map(int,input().split())
n = int(input())
g=[set() for i in range(26)]
a=input()
v=[0]*26
for  i in range(1,n):
    b=input()
    j=0
    while j<min(len(a),len(b)) and a[j]==b[j]:j+=1
    if j<min(len(a),len(b)) and a[j]!=b[j]:
        g[ord(a[j])-97].add(ord(b[j])-97)
    elif len(a)>len(b):
        print("Impossible")
        exit()
    a=b
ans=[]
def dfs(s):
    v[s]=1
    for j in g[s]:
        if v[j]==1:
            print("Impossible")  ###### check DAF directed acylic graph
            exit()

        if v[j]==0:
            dfs(j)
    v[s]=2
    ans.append(chr(s+97))
for i in range(26):
    if v[i]==0:
        dfs(i)
print("".join(reversed(ans)))
