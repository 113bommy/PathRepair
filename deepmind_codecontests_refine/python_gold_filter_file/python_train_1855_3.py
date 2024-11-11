S = input()
N = len(S)

from collections import defaultdict

reddic = defaultdict(int)
bludic = defaultdict(int)

redarray = [0] * (N+1)
bluarray = [0] * (N+1)

for e,c in enumerate(S):

    if c == "2":
        bludic[e+1] += 2
        bluarray[e+1] += 2
    elif c == "1":
        reddic[e+1] += 1
        bludic[e+1] += 1

        redarray[e+1] += 1
        bluarray[e+1] += 1
    elif c == "0":
        reddic[e+1] += 2
        redarray[e+1] += 2

for i in range(1,N+1):
    redarray[i] += redarray[i-1]
    bluarray[i] += bluarray[i-1]

# print("redarray: ", redarray)
# print("bluarray: ", bluarray)

dp = [ [0] * (2*N+1) for _ in range(2*N+1)]
dp[0][0] = 1
MOD = 998244353

for p in range(1, 2*N+1):
    for r in range(0, p):
        idx = p if p <= N else N
        if r < redarray[idx]:
            dp[p][r+1] += dp[p-1][r] % MOD
        if p-1-r < bluarray[idx]:
            dp[p][r] += dp[p-1][r] % MOD
    # print("{:3d}".format(p), dp[p])

print(dp[2*N][redarray[N]]%MOD)