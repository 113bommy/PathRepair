n,k = map(int,input().split())
A = [int(i) for i in input().split()]
dp = ["Second"]+["First"]*k
for i in range(1,k+1):
    win = "Second"
    for a in A:
        if i-a >= 0 and dp[i-a] == "Second":
            win = "First"
    dp[i] = win
print(dp[k])
