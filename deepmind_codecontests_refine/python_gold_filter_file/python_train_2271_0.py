import sys
input = sys.stdin.readline

N = int(input())
wsv = [tuple(map(int, input().split())) for _ in range(N)]
wsv.sort(key=lambda t: t[0]+t[1])
dp = [[0]*(2*10**4+1) for _ in range(N+1)]

for i in range(N):
    w, s, v = wsv[i]
    
    for j in range(2*10**4+1):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        
        if s>=j and j+w<=2*10**4:
            dp[i+1][j+w] = max(dp[i+1][j+w], dp[i][j]+v)

print(max(dp[N]))