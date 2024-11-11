n=int(input())
ans=0
for a in range(1,n+1):
  ans+=(n-1)//a
print(ans)