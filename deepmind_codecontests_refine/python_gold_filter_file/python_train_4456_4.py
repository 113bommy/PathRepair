n=int(input())
xy=[[]for _ in range(n)]
for i in range(n):
  for j in range(int(input())):
    xy[i].append(list(map(int,input().split())))
ans=0
for i in range(1,1<<n):
  syojiki=[(i&(1<<j)!=0)+0 for j in range(n)]
  flag=True
  for j in range(n):
    for x,y in xy[j]:
      if syojiki[x-1]!=y and syojiki[j]==1:flag=False
  if flag:
    ans=max(ans,syojiki.count(1))
print(ans)