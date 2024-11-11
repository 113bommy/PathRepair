n,x=map(int,input().split())
arr=list(map(int,input().split()))
d=0
ans=1
for a in arr:
  d+=a
  if d <= x:
    ans+=1
print(ans)
