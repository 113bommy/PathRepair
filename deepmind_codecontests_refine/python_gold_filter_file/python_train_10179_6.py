N=int(input())
dp=[0]*(10**4+1)
for i in range(1,100+1):
  for j in range(1,100+1):
    for k in range(1,100+1):
      a=(i+j)**2+(k+j)**2+(i+k)**2
      if 10**4<a//2:
        break
      dp[a//2]+=1
for l in range(1,N+1):
  print(dp[l])