n=int(input())
dp=[0,1]
for i in range(2,n+1):
    dp.append(dp[-1]+4*(i-1))
print(dp[n])
