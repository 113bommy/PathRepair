import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n = int(readline())
wsv = [list(map(int,readline().split())) for _ in range(n)]
wsv.sort(key=lambda x:x[0]+x[1])

dp = [[0] * (2*10**4+1) for _ in range(n+1)]
for i in range(n):
    wi,si,vi = wsv[i]
    for j in range(1,2*10**4+1):
        if(j < wi):
            dp[i+1][j] = max(dp[i+1][j-1],dp[i][j])
        elif(j <= wi+si):
            dp[i+1][j] = max(dp[i+1][j-1],dp[i][j],dp[i][j-wi]+vi)
        else:
            dp[i+1][j] = max(dp[i+1][j-1],dp[i][j])

print(dp[-1][-1])