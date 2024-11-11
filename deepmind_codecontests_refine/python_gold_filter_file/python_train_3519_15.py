n,k=map(int,input().split())
v=list(map(int,input().split()))
ans=0
for i in range(k+1):
  l=min(k-i,n)
  for a in range(l+1):
    b=l-a
    if b==0:
      sub=v[:a]
    else:
      sub=v[:a]+v[-b:]
    h=min(len(sub),i)
    for j in range(h):
      m=min(sub)
      if m<0:
        sub.remove(m)
    ans=max(ans,sum(sub))

print(ans)