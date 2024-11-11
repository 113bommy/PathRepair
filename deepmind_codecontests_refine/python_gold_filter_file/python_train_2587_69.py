n,s=map(int,input().split())
ans=0
for i in range(n+1):
  for j in range(n+1):
    if -1<s-i-j<n+1:
      ans+=1
print(ans)
