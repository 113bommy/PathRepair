from collections import deque
import sys
sys.setrecursionlimit(10**7)

N=int(input())
M=N*(N-1)//2
D=[[]for i in range(M)]
F=[[]for i in range(M)]
for i in range(N):
  x=list(map(int,input().split()))
  for j in range(N-2):
    a,b,c=i+1,x[j],x[j+1]
    x1,x2=min(i+1,x[j]),max(i+1,x[j])
    y1,y2=min(i+1,x[j+1]),max(i+1,x[j+1])
    e=M-(N-x1)*(N-x1+1)//2
    f=e+(x2-x1-1)
    g=M-(N-y1)*(N-y1+1)//2
    h=g+(y2-y1-1)
    D[f].append(h)
    F[h].append(f)
    
q=deque()
P=[0]*M
for i in range(M):
  if len(F[i])==0:
    q.append((i,0))

r=[]
while q:
  v1,cnt=q.popleft()
  r.append((v1,cnt))
  for v2 in D[v1]:
    P[v2]+=1
    if P[v2]==len(F[v2]):
      q.append((v2,cnt+1))

if len(r)!=M:
  print(-1)
else:
  print(r[-1][-1]+1)