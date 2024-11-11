from collections import deque
n,q=map(int,input().split())
L=[[]for _ in range(n)]
V=[False]*n
P=[0]*n
for i in range(n-1):
   a,b=map(int,input().split())
   L[a-1].append(b-1)
   L[b-1].append(a-1)
for i in range(q):
   p,x=map(int,input().split())
   P[p-1]+=x
que=deque([0])
while que:
   s=que.popleft()
   V[s]=True
   for ni in L[s]:
       if V[ni]==False:
           P[ni]+=P[s]
           que.append(ni)
print(*P)