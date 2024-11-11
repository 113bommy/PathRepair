n = int(input())
T = list(map(int,input().split()))
V = list(map(int,input().split()))

dp = [[-1]*102 for _ in range(sum(T) + 1)]
dp[0][0] = 0

nt = 0
pt = T[0]
# i 秒から i+1 秒へ配る
delta = [-1,0,1]
for i in range(sum(T)):
    if pt == i:
        nt += 1
        pt += T[nt]
    for j in range(101):
        if j > V[nt] or dp[i][j] == -1:break
        for d in delta:
            nj = j + d
            if 0 <= nj <= V[nt]:
                if d != 0 or j == V[nt]:
                    dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + (j+nj)/2)
                else :
                    dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + j + 0.25)

print(dp[-1][0])
