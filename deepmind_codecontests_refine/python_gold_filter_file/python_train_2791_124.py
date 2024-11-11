import sys
input=sys.stdin.readline
n,k=map(int,input().split())
h=list(map(int,input().split()))
dp=[0]*n
for i in range(1,n):
  kk=max(i-k,0)
  dp[i]=min(d+abs(hh-h[i])for d,hh in zip(dp[kk:i],h[kk:i]))
print(dp[n-1])
