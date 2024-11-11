n,k=map(int,input().split())
ans=0
for i in range(k+1,n+1):
  ans+=(n//i)*(i-k)+max(n%i-k+1,0)
print(n**2 if k==0 else ans)
