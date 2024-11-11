import heapq
n,m=map(int,input().split())
ab=[[] for _ in range(m+1)]
for i in range(n):
  a,b=map(int,input().split())
  if a<=m:
    ab[a].append(-b)

cand=[]
heapq.heapify(cand)
ans=0
for i in range(1,m+1):
  for j in range(len(ab[i])):
    heapq.heappush(cand,ab[i][j])
  if len(cand)>0:
    ans-=heapq.heappop(cand)

print(ans)