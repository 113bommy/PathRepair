N,K= map(int,input().split())
H= list(map(int,input().split()))

def dpinit(ps, val=0):
    res = [val for i in [0]*ps[-1]]
    for i in ps[:-1][::-1]:
        res = [res[:] for k in [0]*i]
    return res

H = [0] + H + [0]
dp = dpinit((N+2,K+2))

for i in range(1,N+2):
    for j in range(K+1):
        l = min(j+1,i)
        cand = [dp[i-k][j-k+1] + max(0, H[i]-H[i-k]) for k in range(1,l+1)]
        dp[i][j] = min(cand)

print(dp[N+1][K])

