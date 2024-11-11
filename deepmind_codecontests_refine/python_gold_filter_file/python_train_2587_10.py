n,k=map(int,input().split())
ans=0
for i in range(n+1):
  for j in range(n+1):
    if 0<=k-i-j<=n:
      ans+=1
print(ans)
