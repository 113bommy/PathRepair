def solve(node):
    global ans
    for i in range(N-1, 0, -1):
        s = 0
        maxi = 0
        num = len(paths[i])-1

        for to in paths[i]:
            s += dp[to]
            if(maxi<dp[to]):
                maxi=dp[to]
        if(i == node and num >= 2):
            num -= 1
            s -= maxi
        
        dp[i] = s / num + 1
    if(ans>dp[1]):
        ans = dp[1]


N, M = map(int, input().split())
paths = [[0]for i in range(N + 1)]
dp = [0 for i in range(N+1)]
ans = 1e12
for i in range(M):
    s, t = map(int, input().split())
    paths[s].append(t)
for i in range(N):
    solve(i)
print(ans)