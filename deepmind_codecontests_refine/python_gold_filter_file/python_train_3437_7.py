from heapq import*
I=float("inf")
def m():
 n=int(input())
 A=[]
 for _ in[0]*n:
  e=list(map(int,input().split()))
  A+=[zip(e[2::2],e[3::2])]
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
