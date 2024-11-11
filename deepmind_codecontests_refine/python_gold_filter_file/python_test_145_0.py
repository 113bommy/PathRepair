import sys
import math
from collections import deque,Counter
from sys import stdin

#sys.setrecursionlimit(10**7)

int1=lambda x: int(x)-1
stinput=lambda :stdin.readline()[:-1]
ii=lambda :int(stinput())
mi=lambda :map(int, stdin.readline().split())
li=lambda :list(mi())
mi1=lambda :map(int1, stdin.readline().split())
li1=lambda :list(mi1())
mis=lambda :map(str, stdin.readline().split())
lis=lambda :list(mis())

from collections import defaultdict
#d=defaultdict(int)
#d=defaultdict(lambda:1)

import heapq
#heapq.heapify(hq)
#heapq.heappop(hq)
#heapq.heappush(hq,1)

mod=10**9+7
Mod=998244353
INF=10**18
ans=0

#UnionFind
from collections import defaultdict

class UnionFind():
    def __init__(self, n, time):
        self.time = time
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        mn=min(self.time[x],self.time[y])
        self.time[x]=mn
        self.time[y]=mn

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        # {0: [0, 2], 1: [1, 3, 4, 5]}
        #　辞書で返す
        # d=uf.all_group_members() で使う
        group_members = defaultdict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members

    def __str__(self):
        return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())



t=ii()
for _ in range(t):
  stinput()
  n,d=mi()
  time=[0]*n
  X=defaultdict(list)
  Y=defaultdict(list)
  for i in range(n):
    x,y,T=mi()
    time[i]=T
    X[x].append((y,i))
    Y[y].append((x,i))
  uf=UnionFind(n,time)
  for x in X:
    s=sorted(X[x])
    m=len(s)
    for i in range(m-1):
      if s[i+1][0]-s[i][0]<=d:
        id1=s[i+1][1]
        id2=s[i][1]
        uf.union(id1,id2)
  for y in Y:
    s=sorted(Y[y])
    m=len(s)
    for i in range(m-1):
      if s[i+1][0]-s[i][0]<=d:
        id1=s[i+1][1]
        id2=s[i][1]
        uf.union(id1,id2)
  #print(uf.all_group_members())
  todo=[]
  for i in uf.roots():
    todo.append(uf.time[i])
  todo.sort(reverse=True)
  ans=0
  for i in range(1,len(todo)):
    if ans<todo[i]:
      ans+=1
  print(ans)