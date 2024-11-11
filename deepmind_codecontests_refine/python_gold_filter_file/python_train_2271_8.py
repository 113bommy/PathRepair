n = int(input())
a = []
for i in range(n):
  x,y,z = map(int,input().split())
  a.append([x+y,x,y,z])
dp = [-1] * 20001
a.sort()
dp[0] = 0
for i in range(n):
  for j in range(20000,-1,-1):
    if dp[j] != -1 and a[i][2]>= j:
      dp[j+a[i][1]] = max(dp[j+a[i][1]],dp[j]+a[i][3])
print(max(dp)) 
