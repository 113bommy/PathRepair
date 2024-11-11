n = int(input())
dp=[]
dp.append(0)
dp.append(1)

for i in range(2,n+1):
    temp=dp[i-1]+4*(i-1)
    dp.append(temp)
print(dp[n])