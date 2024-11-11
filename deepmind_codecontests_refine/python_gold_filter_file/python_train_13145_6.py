from bisect import *
from collections import *
from math import *
from heapq import *
from typing import List
from itertools import *
from operator import *
from functools import *

#------------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase
# region fastio
 
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
#------------------------------------------------------------------------
def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
#------------------------------------------------------------------------

@lru_cache(None)
def fact(x):
    if x<2:
        return 1
    return fact(x-1)*x

@lru_cache(None)
def per(i,j):
    return fact(i)//fact(i-j)

@lru_cache(None)
def com(i,j):
    return per(i,j)//fact(j)

def linc(f,t,l,r):
    while l<r:
        mid=(l+r)//2
        if t>f(mid):
            l=mid+1
        else:
            r=mid
    return l

def rinc(f,t,l,r):
    while l<r:
        mid=(l+r+1)//2
        if t<f(mid):
            r=mid-1
        else:
            l=mid
    return l

def ldec(f,t,l,r):
    while l<r:
        mid=(l+r)//2
        if t<f(mid):
            l=mid+1
        else:
            r=mid
    return l

def rdec(f,t,l,r):
    while l<r:
        mid=(l+r+1)//2
        if t>f(mid):
            r=mid-1
        else:
            l=mid
    return l

def isprime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

def binfun(x):
    c=0
    for w in arr:
        c+=ceil(w/x)
    return c

def lowbit(n):
    return n&-n

class BIT:
    def __init__(self,arr):
        self.arr=arr
        self.n=len(arr)-1
        
    def update(self,x,v):
        while x<=self.n:
            self.arr[x]+=v
            x+=x&-x

    def query(self,x):
        ans=0
        while x:
            ans+=self.arr[x]
            x&=x-1
        return ans

class smt:
    def __init__(self,l,r,arr):
        self.l=l
        self.r=r
        self.value=(1<<31)-1 if l<r else arr[l]
        mid=(l+r)//2
        if(l<r):
            self.left=smt(l,mid,arr)
            self.right=smt(mid+1,r,arr)
            self.value&=self.left.value&self.right.value
        #print(l,r,self.value)
    def setvalue(self,x,val):
        if(self.l==self.r):
            self.value=val
            return
        mid=(self.l+self.r)//2
        if(x<=mid):
            self.left.setvalue(x,val)
        else:
            self.right.setvalue(x,val)
        self.value=self.left.value&self.right.value
    def ask(self,l,r):
        if(l<=self.l and r>=self.r):
            return self.value
        val=(1<<31)-1
        mid=(self.l+self.r)//2
        if(l<=mid):
            val&=self.left.ask(l,r)
        if(r>mid):
            val&=self.right.ask(l,r)
        return val

class UFS:
    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.ranks=[0]*n

    def find(self,x):
        if x!=self.parent[x]:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def union(self,u,v):
        pu,pv=self.find(u),self.find(v)
        if pu==pv:
            return False
        if self.ranks[pu]>=self.ranks[pv]:
            self.parent[pv]=pu
            if self.ranks[pv]==self.ranks[pu]:
                self.ranks[pu]+=1
        else:
            self.parent[pu]=pv

def Prime(n):
    c=0
    prime=[]
    flag=[0]*(n+1)
    for i in range(2,n+1):
        if not flag[i]:
            prime.append(i)
            c+=1
        for j in range(c):
            if i*prime[j]>n: break
            flag[i*prime[j]]=prime[j]
            if i%prime[j]==0: break
    return prime

def dij(s,graph):
    d={}
    d[s]=0
    heap=[(0,s)]
    seen=set()
    while heap:
        dis,u=heappop(heap)
        if u in seen:
            continue
        for v in graph[u]:
            if v not in d or d[v]>d[u]+graph[u][v]:
                d[v]=d[u]+graph[u][v]
                heappush(heap,(d[v],v))
    return d

'''
import time
s=time.time()
for i in range(2000):
    print(0)
e=time.time()
print(e-s)
'''


t=N()
for i in range(t):
    x,y=RL()
    c=RLL()
    #c=[min(c[i],c[(i-1)%6]+c[(i+1)%6]) for i in range(6)]
    if x>=0 and y>=0:
        if x>=y:
            ans=min(c[5]*x+c[1]*y,y*c[0]+(x-y)*c[5],x*c[0]+(x-y)*c[4])
        else:
            ans=min(c[5]*x+c[1]*y,x*c[0]+(-x+y)*c[1],y*c[0]+(-x+y)*c[2])
    elif x<=0 and y<=0:
        x,y=-x,-y
        c=[c[(i+3)%6] for i in range(6)]
        if x>=y:
            ans=min(c[5]*x+c[1]*y,y*c[0]+(x-y)*c[5],x*c[0]+(x-y)*c[4])
        else:
            ans=min(c[5]*x+c[1]*y,x*c[0]+(-x+y)*c[1],y*c[0]+(-x+y)*c[2])
    elif x>=0 and y<=0:
        y*=-1
        ans=min(x*c[5]+y*c[4],(x+y)*c[4]+x*c[0],(x+y)*c[5]+y*c[3])
    else:
        x*=-1
        ans=min(c[2]*x+c[1]*y,c[1]*(x+y)+x*c[3],c[2]*(x+y)+c[0]*y)
    print(ans)

    

