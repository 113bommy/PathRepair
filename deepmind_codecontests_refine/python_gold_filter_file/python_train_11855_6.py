n,m=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(m)]
count=[1]*(n+1)
flag=[False]*(n+1)
flag[1]=True
for a,b in arr:
  count[b]+=1
  count[a]-=1
  if flag[a]==True:
    flag[b]=True
  if count[a]==0:
    flag[a]=False
print(flag.count(True))