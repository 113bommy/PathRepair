while True:
    n = int(input())
    if n == 0:
        break
    dp = [-100000]
    for i in range(n):
        a = int(input())
        dp.append(max(dp[i] + a, a))
    print(max(dp))