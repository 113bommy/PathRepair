def g(i, j, k):
    if i >= n:
        return 0
    if dp[i][j][k] != -1:
        return dp[i][j][k]
    o = g(i+1, j, k)
    c = s[i] != t[0]
    if k >= c:
        o = max(o, g(i+1, j+1, k-c))
    c = s[i] != t[1]
    if k >= c:
        o = max(o, g(i+1, j+(t[0]==t[1]), k-c) + j)
    dp[i][j][k] = o
    return o

n, k = map(int, input().split())
s = input()
t = input()

dp = [[[-1] * (n+1) for _ in [0]*n] for _ in [0]*n]

print(g(0,0,k))