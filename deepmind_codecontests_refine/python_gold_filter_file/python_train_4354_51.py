n = int(input())
INF = 987456325585
arr  = [int(x) for x in input().split()]

# dp[i][j] -> array is left with elements from index i to j, contains max of x-y if player x starts from here

# dp[0][n-1] -> res

dp = []
for i in range(n):
    dp.append([-INF]*n)

for i in range(n-1,-1,-1):
    for j in range(i,n):
        if i == j:
            dp[i][j] = arr[i]
            continue
        dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1])

print(dp[0][n-1])
