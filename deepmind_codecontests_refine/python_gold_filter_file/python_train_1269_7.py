n,m=map(int,input().split())
mod=10**9+7
if n>m:
  n,m=m,n
if m==1:
  print(2)
else:
  DP=[[0]*2 for _ in range(m)]
  DP[1][0]=2
  DP[1][1]=2
  for i in range(2,m):
    DP[i][0]=DP[i-1][1]%mod
    DP[i][1]=(DP[i-1][0]+DP[i-1][1])%mod

  a=DP[m-1][0]+DP[m-1][1]
  if n==1:
    print(a%mod)
  else:
    ans=a-2
    ans+=DP[n-1][0]+DP[n-1][1]
    print(ans%mod)