from collections import defaultdict
import os
import sys
from io import BytesIO, IOBase
from types import GeneratorType
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
sys.setrecursionlimit(7*10**4)


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

@bootstrap
def dfs(u):
    vis[u]=1
    for j in adj[u]:
        if d[j,u]==1:
            d1[j,u]="+"

        if d[u,j]==1:
            d1[u,j]="-"

        if d3[u,j]:
            if not vis[j]:
                yield dfs(j)

    yield

@bootstrap
def dfs2(u):
    vis[u] = 1
    for j in adj[u]:
        if not vis[j]:
            if d[j, u] == 1:
                d2[j, u] = "-"

            if d[u, j] == 1:
                d2[u, j] = "+"


            yield dfs2(j)

    yield











n,m,s=map(int,input().split())
edges=[]
adj=[[] for i in range(n+1)]
d=defaultdict(lambda:0)
d3=defaultdict(lambda:0)
d1=defaultdict(lambda:"+")
d2=defaultdict(lambda:"+")


for j in range(m):
    b=list(map(int,input().split()))

    if b[0]==1:
        adj[b[1]].append(b[2])
        d3[b[1],b[2]]=1

    else:
        adj[b[1]].append(b[2])
        adj[b[2]].append(b[1])
        d[b[1],b[2]]=1
        edges.append([b[1],b[2]])

vis=[0]*(n+1)
dfs(s)
m1=vis.count(1)

vis=[0]*(n+1)
dfs2(s)
m2=vis.count(1)

res1=[]
res2=[]

for j in edges:
    res1.append(d1[j[0],j[1]])
    res2.append(d2[j[0],j[1]])

print(m2)
print("".join(res2))
print(m1)
print("".join(res1))





