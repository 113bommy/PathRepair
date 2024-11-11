import sys
input=sys.stdin.readline
n,x=map(int,input().split())
vo=[list(map(int,input().split())) for i in range(n)]
d=[[] for i in range(x+1)]
for l,r,c in vo:
  if r-l+1<=x:
    d[r-l+1].append([l,c])
mins=[[] for i in range(x+1)]
for i in range(1,x+1):
  if len(d[i])==0:
    continue
  d[i].sort()
  cum_min_cost=10**18
  for j in range(len(d[i]))[::-1]:
    cum_min_cost=min(cum_min_cost,d[i][j][1])
    mins[i].append(cum_min_cost)
  mins[i]=mins[i][::-1]
ans=10**18
for i in range(1,x+1):
  if len(d[i])==0 or len(d[x-i])==0:
    continue
  for j in range(len(d[i])):
    pos,v=d[i][j]
    l=-1
    r=len(d[x-i])
    while r-l>1:
      mid=(r+l)//2
      if d[x-i][mid][0]>i+pos-1:
        r=mid
      else:
        l=mid
    if r<len(d[x-i]):
      ans=min(ans,mins[x-i][r]+v)
if ans==10**18:
  print(-1)
else:
  print(ans)