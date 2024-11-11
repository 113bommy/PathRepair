n,k = map(int,input().split())
aa = list(map(int,input().split()))

dp = [-1]*(k+1)

for i in range(1,k+1):
  for j in range(n):
    if i >= aa[j]:
      dp[i] = max(dp[i],-dp[i-aa[j]])

if dp[k]>0:
  print('First')  
else:
  print('Second')      