"""
E-Knapsack2
Wが10**9まであるのでdpの置き方を工夫する。
dp[i]:=価値がiのときのナップザックの重さ
"""
N,W = map(int,input().split())
dp = [0]+[W+1]*(N*10**3)
for i in range(N):
    w,v = map(int,input().split())
    for j in range(N*10**3+1-v)[::-1]:
        dp[j+v] = min(dp[j+v],dp[j]+w)
for i in range(N*10**3+1)[::-1]:
    if dp[i]<=W:
        print(i)
        exit()