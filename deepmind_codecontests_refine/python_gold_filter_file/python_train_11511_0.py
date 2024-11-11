import heapq
from bisect import bisect_right
from collections import defaultdict
import os
import sys
from io import BytesIO, IOBase
from collections import defaultdict
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


n=int(input())
res=[]
curr,we=map(int,input().split())
for j in range(n-1):
    p,q=map(int,input().split())
    res.append([p,q-p])

res.sort(reverse=True)
li=[]
j=0
ans=n
tot=0
while(j<n-1):
    if res[j][0]>curr:
        heapq.heappush(li,res[j][1]+1)
        j+=1
    else:
        ans=min(ans,j+1-tot)
        try:
            p=li[0]
        except:
            p=float("inf")
        if curr>=p:
            curr-=p
            heapq.heappop(li)
            tot+=1
        else:
            break

while(curr>=0):
    ans = min(ans, j + 1 - tot)
    try:
        p = li[0]
    except:
        p = float("inf")
    if curr >= p:
        curr -= p
        heapq.heappop(li)
        tot += 1
    else:
        break


print(ans)





