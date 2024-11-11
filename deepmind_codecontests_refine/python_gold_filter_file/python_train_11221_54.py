H,N = map(int,input().split())

data = []

for i in range(N):
  A,B = map(int,input().split())
  data.append([A,B])

dp = [0] * (H+1)

for i in range(1,H+1):
    dp[i] = min([dp[max(0,i-data[j][0])] + data[j][1] for j in range(N)])
    #print(dp)
print(dp[H])