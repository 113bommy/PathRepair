n=int(input())
k=int(input())
ans=1
for _ in range(n):
  ans=min(ans*2,ans+k)
print(ans)