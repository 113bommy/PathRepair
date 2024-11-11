# ------------------- fast io --------------------
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
 
# ------------------- fast io --------------------
from collections import deque,defaultdict
import heapq
for j in range(int(input())):
    n=int(input());tree=[set([]) for s in range(n)];mod=10**9 +7
    for s in range(n-1):
        u,v=map(int,input().split())
        u-=1;v-=1
        tree[u].add(v);tree[v].add(u)
    m=int(input());vals=list(map(int,input().split()));depth=defaultdict(list);dd={}
    #find the depth
    q=deque([]);vis=set([]);cv=0;pr=1
    for s in range(n):
        if len(tree[s])>=1:
            q.append(s);vis.add(s)
            break
    while len(q)>0:
        vv=q.popleft()
        for s in tree[vv]:
            if not(s in vis):
                q.append(s);vis.add(s)
        depth[cv].append(vv);dd[vv]=cv;pr-=1
        if pr==0:
            cv+=1;pr=len(q)
    #
    cv=max(depth.keys())
    dist=defaultdict(list)
    while cv>0:
        for s in depth[cv]:
            for b in tree[s]:
                if cv>dd[b]:
                    dist[b].append(sum(dist[s])+1)
        cv-=1
    visits=[];heapq.heapify(visits);vals.sort();ans=0
    for s in dist.keys():
        while len(dist[s])>0:
            v1=dist[s].pop()
            if v1!=0:
                heapq.heappush(visits,-v1*(n-v1))
    if len(vals)>len(visits):
        prod=1
        while len(vals)>=len(visits):
            prod*=vals.pop();prod=prod%mod
        ans+=-heapq.heappop(visits)*prod%mod
    while len(visits)>0:
        v2=-heapq.heappop(visits)
        if len(vals)>0:
            ans+=v2*vals.pop()
        else:
            ans+=v2
        ans=ans%mod
    print(ans)