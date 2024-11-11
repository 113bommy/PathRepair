import itertools
import sys

def findRoot(uf,value):
  if uf[value]==None:
    return value
  else:
#経路圧縮
    uf[value]=findRoot(uf,uf[value])
    return uf[value]


sys.setrecursionlimit(50000)
n,m=[int(x) for x in input().split(' ')]

uf=[None]*n
b=[]
s=[1]*n
r=[]

for x in range(0,m):
  b.append([int(x)-1 for x in input().split(' ')])

for x in b[::-1]:
  r1=findRoot(uf,x[0])
  r2=findRoot(uf,x[1])

  if r1==r2:
    r.append(0)
  else:
    r.append(s[r1]*s[r2])
#木の結合
    uf[r2]=r1
    s[r1]+=s[r2]

for x in itertools.accumulate(r[::-1]):
  print(x)
