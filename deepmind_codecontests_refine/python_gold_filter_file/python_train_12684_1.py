alp = [chr(i) for i in range(97, 97+26)]

import sys
input = sys.stdin.readline

S = input().rstrip()
N = len(S)

dp = [[N]*26 for _ in range(N+1)]

Best = [-1]*(N+1)

for i in reversed(range(N)):
    s = S[i]
    b = 10**14
    for k in range(26):
        if Best[dp[i+1][k]] < b:
            b = Best[dp[i+1][k]]
        if s == alp[k]:
            dp[i][k] = i
        else:
            dp[i][k] = dp[i+1][k]
    Best[i] = b+1

b = 10**14
for k in range(26):
    if Best[dp[0][k]] < b:
        b = Best[dp[0][k]]
L = b+1

ans = ""
ind = -1
for _ in range(L+1):
    best = Best[max(dp[ind+1])]
    for k in range(26):
        if Best[dp[ind+1][k]] == best:
            ans += alp[k]
            if ind != N:
                ind = dp[ind+1][k]
            break
print(ans)