from collections import deque
n,q=map(int,input().split())
K=[[] for _ in range(n)]
V=[False]*n
P=[0]*n
for i in range(n-1):
   a,b=map(int,input().split())
   K[a-1].append(b-1)
   K[b-1].append(a-1)
for i in range(q):
   q,x=map(int,input().split())
   P[q-1]+=x
que=deque([0])
while que:
   s=que.popleft()
   V[s]=True
   for ni in K[s]:
      if V[ni]==False:
         P[ni]+=P[s]
         que.append(ni)
print(*P)
   