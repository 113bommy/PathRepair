n=int(input())
ar=list(map(int,input().split()))
dp=[0]*(10**6)
for i in range(n):
  m=ar[i]-i
  dp[m]+=ar[i]
print(max(dp))

