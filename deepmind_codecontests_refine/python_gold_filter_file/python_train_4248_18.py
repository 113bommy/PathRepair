N=int(input())
if N%2==1:
  print(0)
  exit(0)
  
ans=0
n=N
div=10
while n>=div:
  ans+=n//div
  div*=5
print(ans)