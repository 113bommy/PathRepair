from fractions import gcd
N,K=map(int,input().split())
A=list(map(int,input().split()))
maxi=max(A)

if K>maxi:
  ans="IMPOSSIBLE"
else:
  t=A[0]
  for i in range(1,N):
    t = gcd(t,A[i])
  if K%t==0:
    ans="POSSIBLE"
  else:
    ans="IMPOSSIBLE"
    
print(ans)