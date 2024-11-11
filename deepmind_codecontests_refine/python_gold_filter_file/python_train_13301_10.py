ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
tma = lambda :tuple(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
import collections
import math
import itertools
import heapq as hq
R,C,K = ma()
V = [[0 for i in range(R+1)] for j in range(C+1)]
for i in range(K):
    r,c,v = ma()
    V[c][r] = v
dp_prev = [[0]*4 for i in range(C+1)]
dp_nex = [[0]*4 for i in range(C+1)] #dp[h][k] h列目でmax kこまで選んだ時の最大値
for r in range(1,R+1):
    for c in range(1,C+1):
        v = V[c][r]
        for k in range(4):
            if k==0:
                dp_nex[c][0] = max(dp_prev[c][3],dp_nex[c-1][0])
            elif k >0:
                dp_nex[c][k] = max(dp_nex[c-1][k],dp_nex[c-1][k-1]+v,dp_prev[c][3]+v)
    dp_prev,dp_nex = dp_nex,dp_prev
    #print(dp_prev)


print(dp_prev[C][3])
