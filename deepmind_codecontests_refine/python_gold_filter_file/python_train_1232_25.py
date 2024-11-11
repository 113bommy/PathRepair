from collections import defaultdict
import sys
sys.setrecursionlimit(10**9)

n=int(input())
dct=defaultdict(list)

for i in range(n-1):
  a,b,c=map(int,input().split())
  dct[a]+=[[b,c]]
  dct[b]+=[[a,c]]


q,k=map(int,input().split())
lk=[0]*(n)

def dfs(v,p,d):
  lk[v-1]=d

  for l in dct[v]:
    if l[0]==p or lk[l[0]-1]!=0:
      continue
    else:
      dfs(l[0],v,d+l[1])
  return

dfs(k,-1,0)



for i in range(q):
  x,y=map(int,input().split())
  print(lk[x-1]+lk[y-1])
