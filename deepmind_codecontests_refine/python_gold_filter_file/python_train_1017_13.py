n,k,s=map(int,input().split())
if s==10**9:
  A=[s]*k+[1]*(n-k)
else:
  A=[s]*k+[s+1]*(n-k)
print(*A)