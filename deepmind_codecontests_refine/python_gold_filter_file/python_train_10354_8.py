n = int(input())
h = [0] + list(map(int, input().split()))
dp = [0] * (n + 1)
energy = 0
for i in range(1, n + 1):
    d = h[i] - h[i - 1]
    if d <= energy:
        energy -= d
        d = 0
    else:
        d -= energy
        energy = 0
    dp[i] = dp[i - 1] + d
print(dp[n])
