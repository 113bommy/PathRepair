n,t=map(int,input().split())
arr=map(int,input().split())

ans=0
for i in arr:
  t-=86400-i
  ans+=1
  if t<=0:
    break
print(ans)