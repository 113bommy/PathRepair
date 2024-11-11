n,totaltea=map(int,input().split())
ar=list(map(int,input().split()))
ans=[0]*n
for i in range(n):ans[i]=(ar[i]+1)//2
if sum(ans)>totaltea:print(-1)
else:
  for i in range(n):
    ar[i]=[ar[i],i]
  ar=sorted(ar)[::-1]
  remain=totaltea-sum(ans)
  for i in range(n):
    if remain==0:break
    k=min(remain,ar[i][0]-ans[ar[i][1]])
    ans[ar[i][1]]+=k
    remain-=k
  if remain!=0:print(-1)
  else:print(*ans)
