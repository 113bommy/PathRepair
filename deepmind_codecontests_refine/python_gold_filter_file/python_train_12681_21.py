S = input()
T = input()
lenS = len(S)
lenT = len(T)
dp = [[0]*(lenT+1)for _ in range(lenS+1)]

for i in range(1,lenS+1):
    for j in range(1,lenT+1):
        if S[i-1]==T[j-1]:
            dp[i][j]=dp[i-1][j-1]+1
        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
ans = ""
m = lenS
n = lenT
while m and n:
    if dp[m][n]==dp[m-1][n]:
        m -= 1
    elif dp[m][n]==dp[m][n-1]:
        n -= 1
    else:
        m -= 1
        n -= 1
        ans = T[n]+ans

print(ans)
