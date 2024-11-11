from heapq import heappush,heappop

n,m=[int(x) for x in input().rstrip().split()]
ab=[[] for i in range(10**5)]

for i in range(n):
  a,b=[int(x) for x in input().rstrip().split()]
  if a<=m:
    ab[m-a].append(-b)

ans=0
l=[]
for i in range(m-1,-1,-1):
  for b in ab[i]:
    heappush(l,b)

  if l:
    ans-=heappop(l)

print(ans)
