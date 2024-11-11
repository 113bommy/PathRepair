from  itertools import accumulate
n,m=map(int,input().split())
arr1=list(map(int,input().split()))
arr1=sorted(arr1)
arr=list(accumulate(arr1))
dp=[0]*(n)
ans=0
for i in range(n):
  if i<m:dp[i]=arr[i]
  else:dp[i]=dp[i-m]+arr[i]
print(*dp)
