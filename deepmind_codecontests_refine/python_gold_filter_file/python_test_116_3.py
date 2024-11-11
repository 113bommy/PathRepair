
import sys
from sys import stdin

tt = int(stdin.readline())

ANS = []
mod = 998244353

for loop in range(tt):

    n = int(stdin.readline())
    a = list(map(int,stdin.readline().split()))

    dp = [[0,0] for i in range(n+2)]
    dp[0][0] = 1

    for i in a:

        ch = []

        #put same
        ch.append( (i+1,0,dp[i][0]) )

        #put -1
        ch.append( (i+1,0,dp[i+1][0]) )
        ch.append( (i+1,1,dp[i+1][1]) )

        #put +1
        ch.append( (i-1,1,dp[i-1][0]) )
        ch.append( (i-1,1,dp[i-1][1]) )

        for x,y,p in ch:
            dp[x][y] += p
            dp[x][y] %= mod

    ans = 0
    for i in range(n+2):
        ans += dp[i][0] + dp[i][1]

    ans -= 1
    ans %= mod
    ANS.append(str(ans))

print ("\n".join(ANS))
