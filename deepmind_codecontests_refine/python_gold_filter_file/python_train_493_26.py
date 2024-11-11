n=int(input())
ans=0
for i in range(n-1):
  a=i+1
  ans+=(n-1)//a
print(ans)