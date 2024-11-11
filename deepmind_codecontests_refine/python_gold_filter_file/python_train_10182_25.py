#12:40
n = int(input())
a1,a2,a3 = map(int,input().split())
b1,b2,b3 = map(int,input().split())
dp = [0] * (n+1)
for i in range(1,n+1):
  tmp = dp[i-1]+1
  if i-a1 >= 0:
    if dp[i-a1]+b1 > tmp:
      tmp = dp[i-a1]+b1
  if i-a2 >= 0:
    if dp[i-a2]+b2 > tmp:
      tmp = dp[i-a2]+b2
  if i-a3 >= 0:
    if dp[i-a3]+b3 > tmp:
      tmp = dp[i-a3]+b3
  dp[i] = tmp
m = dp[-1]
#print(dp)
#print(m)
dp = [0] * (m+1)
for j in range(1,m+1):
  tmp = dp[j-1]+1
  if j-b1 >= 0:
    if dp[j-b1]+a1 > tmp:
      tmp = dp[j-b1]+a1
  if j-b2 >= 0:
    if dp[j-b2]+a2 > tmp:
      tmp = dp[j-b2]+a2
  if j-b3 >= 0:
    if dp[j-b3]+a3 > tmp:
      tmp = dp[j-b3]+a3
  dp[j] = tmp
print(dp[-1])