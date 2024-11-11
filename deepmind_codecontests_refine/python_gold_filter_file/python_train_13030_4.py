# by the authority of GOD     author: manhar singh sachdev #

import os,sys
from io import BytesIO, IOBase

def bridges(n,path):
    poi,start,low,st,time = [0]*n,[0]*n,[10**10]*n,[0],0
    visi,edg = [1]+[0]*(n-1),[]
    while len(st):
        x,y = st[-1],path[st[-1]]
        while poi[x] != len(y) and visi[y[poi[x]]]:
            if len(st) > 1 and y[poi[x]] != st[-2]:
                low[x] = min(low[x],start[y[poi[x]]])
                if start[y[poi[x]]] < start[x]:
                    edg.append((x+1,y[poi[x]]+1))
            poi[x] += 1
        if poi[x] == len(y):
            zz = st.pop()
            if len(st):
                low[st[-1]] = min(low[st[-1]],low[zz])
                if low[zz] > start[st[-1]]:
                    return []
        else:
            time += 1
            i = y[poi[x]]
            visi[i] = 1
            st.append(i)
            start[i] = time
            poi[x] += 1
            edg.append((x+1,i+1))
    return edg

def main():
    n,m = map(int,input().split())
    path = [[] for _ in range(n)]
    for _ in range(m):
        u1,v1 = map(lambda xx:int(xx)-1,input().split())
        path[u1].append(v1)
        path[v1].append(u1)
    x = bridges(n,path)
    if not len(x):
        print(0)
    else:
        for i in x:
            print(*i)

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