n,k=map(int,input().split())
v=list(map(int,input().split()))
ans=0
for a in range(min(k,n)+1):
  for b in range(min(k,n)-a+1):
    t=v[:a]
    t+=v[n-b:]
    t.sort()
    for i in range(k-(a+b)):
      if len(t) and t[0]<0:
        t.pop(0)
    ans=max(ans,sum(t))
print(ans)
