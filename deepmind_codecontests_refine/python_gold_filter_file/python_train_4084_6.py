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
import math
import bisect
#for _ in range(int(input())):
from collections import  Counter
#sys.setrecursionlimit(10**6)
#dp=[[-1 for i in range(n+5)]for j in range(cap+5)]
#arr= list(map(int, input().split()))
#n,m= map(int, input().split())
#arr= list(map(int, input().split()))
#for _ in range(int(input())):
import bisect
#n=int(input())
#for _ in range(int(input())):
from  collections import deque
#n,q= map(int, input().split())
#rr =deque(map(int, input().split()))
#int(input())
for _ in range(1):
    n = int(input())
    #n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    if n==1:
        print(arr[0])
    else:
        pre = [0] * n
        s = [0] * n
        s[-1] = ~arr[-1]
        pre[0] = ~arr[0]
        ans = -1
        var = 0
        for i in range(1, n):
            pre[i] = pre[i - 1] & ~arr[i]
        for i in range(n-2, -1, -1):
            s[i] = s[i + 1] & ~arr[i]
        for i in range(n):
            if i==0:
                cnt=arr[i]&s[i+1]
            elif i==n-1:
                cnt=pre[i-1]&arr[i]
            else:
                cnt = pre[i - 1]&s[i+1]&arr[i]
            if cnt>=var:
                var=cnt

                ans=arr[i]
        if ans!=-1:
            arr.remove(ans)
            print(*([ans]+arr))
        else:
            print(*arr)




