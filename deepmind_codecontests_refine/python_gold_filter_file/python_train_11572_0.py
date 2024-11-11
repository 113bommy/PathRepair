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
from collections import *
from operator import itemgetter , attrgetter
from decimal import *
import bisect
import math
import heapq as hq
MOD=10**9 +7



def pow(a,b,m):
    ans=1
    while b:
        if b&1:
            ans=(ans*a)%m
        b//=2
        a=(a*a)%m
    return ans
vis=[]
graph=[]
def dfs(v):
    if vis[v]: return 0
    vis[v]=True

    temp=0
    for vv in graph[v]:
        temp+=dfs(vv)
    return 1+temp
def ispalindrome(s):
    if s[:]==s[::-1]:
        return 1
    return 0
def f(n):
    if n<5:
        return max(1,n-1)
    if n%2 or n%4==0:
        return n-f(n-1)
    return n-f(n//2)

n=int(input())
q1=0
q2=0
s1=input()
s2=input()
l1=[]
l2=[]
for i in range(n):
    if s1[i]=="?":
        q1+=1
        l1.append(["zz",i+1])
    else:
        l1.append([s1[i],i+1])
    if s2[i]=="?":
        q2+=1
        l2.append(["zz",i+1])
    else:
        l2.append([s2[i],i+1])
i=0
j=0
count=0
ans=[]
l1.sort()
l2.sort()

temp1=[i for i in range(n+1)]
temp2=[i for i in range(n+1)]
while i<n and j<n:
    #print(i,j,l1[i][0],l2[j][0])
    if l1[i][0]=="zz" or l2[j][0]=="zz":
        break
    if l1[i][0]==l2[j][0]:
        count+=1
        ans.append([l1[i][1],l2[j][1]])
        temp1[l1[i][1]]=-1
        temp2[l2[j][1]]=-1
        i+=1
        j+=1

    elif l1[i][0]<l2[j][0]:
        i+=1
    else:
        j+=1
i=0

t=min(n,count+q1+q2)-len(ans)
for j in range(0,min(q1,t)):
        while temp2[l2[i][1]]==-1:
            i+=1
        temp2[l2[i][1]]=-1
        ans.append([l1[n-j-1][1],l2[i][1]])
i=0
t = min(n, count + q1+q2) - len(ans)
for j in range(0,t):
        while temp1[l1[i][1]]==-1:
            i+=1
        temp1[l1[i][1]]=-1
        ans.append([l1[i][1],l2[n-j-1][1]])

print(min(n,count+q1+q2))
for i in range(len(ans)):
    print(*ans[i])
