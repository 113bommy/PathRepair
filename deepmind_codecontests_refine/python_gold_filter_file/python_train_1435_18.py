from collections import deque
n,m=map(int,input().split())
adj=[[] for _ in range(n)]
for _ in range(m):
  a,b =map(int,input().split())
  a-=1
  b-=1
  adj[a].append(b)
  adj[b].append(a)
ans=[0]*n
que=deque([])
que.append(0)
while que:
  e=que.popleft()
  for i in adj[e]:
    if ans[i]!=0:
      continue
    ans[i]=e+1
    que.append(i)
print("Yes")
for i in range(1,n):
  print(ans[i])