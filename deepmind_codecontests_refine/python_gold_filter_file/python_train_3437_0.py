import sys
from heapq import*
e=sys.stdin.readline
I=float("inf")
def m():
 n=int(e())
 A=[]
 for _ in[0]*n:
  b=list(map(int,e().split()))
  A+=[zip(b[2::2],b[3::2])]
 d=[0]+[I]*n
 H=[(0,0)]
 while H:
  u=heappop(H)[1]
  for v,c in A[u]:
   t=d[u]+c
   if d[v]>t:
    d[v]=t
    heappush(H,(t,v))
 print('\n'.join(f'{i} {d[i]}'for i in range(n)))
m()
