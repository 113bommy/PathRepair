#https://atcoder.jp/contests/dp/tasks/dp_f
#2019-01-14
S = input()
T = input()

#初期化
dp = [[0 for i in range(len(T)+1)] for j in range(len(S)+1)]

#DP
for i in range(len(S)):
    for j in range(len(T)):
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j], dp[i][j] + (S[i] == T[j]))

st = []

x = len(S)
y = len(T)
while x > 0 and y > 0:
    if dp[x][y] == dp[x-1][y]: x -= 1
    elif dp[x][y] == dp[x][y-1]: y -= 1
    else: 
        x -= 1
        y -= 1
        st += S[x]
print("".join(reversed(st)))