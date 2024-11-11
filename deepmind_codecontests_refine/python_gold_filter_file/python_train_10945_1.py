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
#######################################
import sys,threading
sys.setrecursionlimit(400000)
threading.stack_size(10**8)
def dfs(x,y,t):
    global v,l1,l2,adj,d,ans,l3,c
    v[x]=1
    l1[x]=t
    l2[x]=t
    for i in adj[x]:
        if not v[i]:
            if x==1:
                c+=1
            dfs(i,x,t+1)
            if l2[i]<=l1[x]:
                l2[x]=l2[i]
                ans.append([x,i])
                if x==1:
                    d-=1
            else:
                ans.append([x,i])
                if x==1:
                    d-=1
        else:
            if i!=y:
                if l2[i]<l1[x]:
                    l2[x]=l2[i]
                    if i==1:
                        l3.append([x,(y,x)])
def main():
    global v,l1,l2,adj,d,ans,l3,c
    n,m,d=map(int,input().split())
    d1=d
    adj=[[] for i in range(n+1)]
    v=[0]*(n+1)
    l1=[0]*(n+1)
    l2=[0]*(n+1)
    l3=[]
    ans=[]
    c=0
    for i in range(m):
        x,y=map(int,input().split())
        adj[x].append(y)
        adj[y].append(x)
    if len(adj[1])<d:
        print("NO")
    else:
        dfs(1,0,0)
        a="YES"
        from collections import defaultdict
        dd=defaultdict(int)
        if c>d1:
            a="NO"
        elif c<d1:
            for i in l3:
                if d==0:
                    break
                ans.append([1,i[0]])
                dd[i[1]]=1
                d-=1
        print(a)
        if a=="YES":
            for i in ans:
                x,y=i
                if dd[(x,y)]==0:
                    print(*i)
t=threading.Thread(target=main)
t.start()
t.join()

        
        
        



    
