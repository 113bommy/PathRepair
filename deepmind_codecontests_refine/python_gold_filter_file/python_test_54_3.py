
###pyrival template for fast IO
import os
import sys
from io import BytesIO, IOBase
##########region fastio
BUFSIZE = 8192
###pyrival template for fast IO
class FastIO(IOBase):
    newlines = 0
    ###pyrival template for fast IO
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    ###pyrival template for fast IO
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    ###pyrival template for fast IO
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    ###pyrival template for fast IO
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    ###pyrival template for fast IO
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
###pyrival template for fast IO
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

from collections import deque
t=int(input())
def cycle_bfs(graph,n,node):###odd len cycle
    q=deque([node]);color[node]=0
    zero=0
    one=0
    while q:
        currnode=q.popleft();visited[currnode]=True;
        if color[currnode]==0:
            currcolor=1;
            if currnode<=n:
                zero+=1
        else:
            currcolor=0;
            if currnode<=n:
                one+=1
        if currnode in graph:
            for neighbour in graph[currnode]:
                if visited[neighbour]==False:
                    visited[neighbour]=True
                    color[neighbour]=currcolor
                    q.append(neighbour)
                else:
                    if color[neighbour]!=currcolor:
                        return False,0
    return True,max(one,zero)

while t:
    t-=1
    n,m=[int(x) for x in input().split()]
    ans=[None for x in range(n+1)]
    graph={x:set() for x in range(1,n+1)}
    fake=n+1
    visited=[False for x in range(n+1)]
    for _ in range(m):
        a,b,c=[x for x in input().split()]
        a=int(a);b=int(b)
        if c=="imposter":
            graph[a].add(b)
            graph[b].add(a)
        else:
            graph[fake]=set()
            graph[fake].add(a)
            graph[a].add(fake)
            graph[fake].add(b)
            graph[b].add(fake)
            fake+=1
            visited.append(False)

    color=[None for x in range(len(visited))]
    ans=True
    res=0
    for node in range(1,n+1):
        if visited[node]==False:
            ans,v=cycle_bfs(graph,n,node)
            res+=v
            if ans==False:
                break

    if ans:
        print(res)
    else:
        print(-1)

