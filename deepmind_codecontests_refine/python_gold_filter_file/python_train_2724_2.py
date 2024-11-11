import sys, math
input = sys.stdin.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

import collections as col
import math

M = 10**8

#in the case 2 3 1 2
"""
0
1
--
dp[2][1][1][1]=1
01
dp[2][0][1][1]=1
10
dp[2][1][2][2]=1
11
--
dp[3][0][1][2]=1
010
dp[3][1][2][2]=1
011
dp[3][1][1][2]=1
101
dp[3][0][1][1]=1
110
"""

def solve():
    N1, N2, K1, K2 = getInts()
    dp = [[col.defaultdict(lambda: col.defaultdict(int)) for j in range(2)] for i in range(N1+N2+1)]
    #parameters are: total number, last one, number of consecutive at suffix, total number of that many
    dp[1][0][1][1] = 1
    dp[1][1][1][1] = 1
    for i in range(2,N1+N2+1):
        for j in dp[i-1][1]:
            for k in dp[i-1][1][j]:
                #we have k of type one, and therefore i-1-k of type 0, and we are adding one more
                if i-k <= N1:
                    dp[i][0][1][i-k] += (dp[i-1][1][j][k])%M
        for j in dp[i-1][0]:
            for k in dp[i-1][0][j]:
                if i-k <= N2:
                    dp[i][1][1][i-k] += (dp[i-1][0][j][k])%M
        for j in range(2,min(i+1,K1,N1)+1):
            for k in dp[i-1][0][j-1]:
                if k+1 <= N1 and i-k-1 <= N2 and j <= K1:
                    dp[i][0][j][k+1] = (dp[i-1][0][j-1][k])%M
        for j in range(2,min(i+1,K2,N2)+1):
            for k in dp[i-1][1][j-1]:
                if k+1 <= N2 and i-k-1 <= N1 and j <= K2:
                    dp[i][1][j][k+1] = (dp[i-1][1][j-1][k])%M
        
        #add a footman: take the number ending in a horseman, and the number ending in a footman but fewer than K1 consecutive footmen
        #same for horseman
        #so actually for each value 1 to N1+N2, we need to store the number of sequences ending in j consecutive footmen / horsemen
    ans = 0
    for x in dp[N1+N2][0]:
        for y in dp[N1+N2][0][x]:
            ans += dp[N1+N2][0][x][y]
            ans %= M
    for x in dp[N1+N2-1][1]:
        for y in dp[N1+N2][1][x]:
            ans += dp[N1+N2][1][x][y]
            ans %= M
    #print(dp[N1+N2][0])
    #print(dp[N1+N2][1])
    return ans
    
print(solve())
    

