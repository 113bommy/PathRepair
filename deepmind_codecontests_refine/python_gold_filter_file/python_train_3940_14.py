n=int(input())
k=int(input())
ans=1
for _ in range(n):
  ans+=min(ans,k)
print(ans)