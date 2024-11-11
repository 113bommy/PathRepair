n,x=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
ans=0
for i in range(n):
  if a[i]<=x:
    x=x-a[i]
    ans=ans+1
if ans==n and x>0:
  ans=ans-1
print(ans)
