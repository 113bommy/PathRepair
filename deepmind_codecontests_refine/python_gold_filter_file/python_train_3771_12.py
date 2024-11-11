#!/usr/bin/python3
# @Author  : indiewar

n = int(input())
s = input()
dp = [0 for i in range(30)]
ans = [1 for i in range(n)]

for i in range(n):
    tmp = ord(s[i]) - ord('a')
    for j in range(tmp+1,26):
        ans[i] = max(ans[i],dp[j]+1)
    dp[tmp] = ans[i]

print(max(ans))

for i in ans:
    print(i,end=" ")