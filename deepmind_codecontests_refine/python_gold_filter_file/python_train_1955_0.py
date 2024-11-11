N = int(input())
dp = [[0]*(19) for _ in range(19)]
ans = 0
for _ in range(N):
    a = round(float(input())*10**9)
    two = 0
    five = 0
    while a%2 == 0:
        a //= 2
        two += 1
    while a%5 == 0:
        a //= 5
        five += 1
    two = min(two,18)
    five = min(five,18)
    ans += dp[18-two][18-five]
    for i in range(two+1):
        for j in range(five+1):
            dp[i][j] += 1
print(ans)