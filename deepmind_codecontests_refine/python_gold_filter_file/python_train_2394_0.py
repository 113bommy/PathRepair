N, C = map(int, input().split())
events = []
for i in range(N):
    events.append(list(map(int, input().split())))

def solve():
    L = 250
    dp = [[-10**18]*(L+1) for i in range(C+1)]
    for j in range(C+1):
        dp[j][0] = 0
    for a, b, c in events:
        for j in range(C-c, -1, -1):
            for k in range(L+1):
                if k + (b-a) <= 0:
                    dp[j+c][a-k-b] = max(dp[j+c][a-k-b], dp[j][k]+k+b)
                else:
                    dp[j+c][k+b-a] = max(dp[j+c][k+b-a], dp[j][k]+a)
                if k + (a-b) <= L:
                    dp[j+c][k+a-b] = max(dp[j+c][k+a-b], dp[j][k]+b)
    ans = 0
    for j in range(C+1):
        ans = max(ans, max(dp[j]))
    return ans
print(solve())