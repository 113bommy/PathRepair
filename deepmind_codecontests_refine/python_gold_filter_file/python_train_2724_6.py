n1,n2,k1,k2 = map(int,input().split())
dp = []
for i in range(n1+1):
    t = []
    for j in range(n2+1):
        u = []
        for g in range(k1+1):
            v = []
            for h in range(k2+1):
                v.append(-1)
            u.append(v)
        t.append(u)
    dp.append(t)


def solve(t1,t2,c1,c2):
    if c1>k1 or c2>k2 or t1>n1 or t2>n2:
        return 0
    if t1==n1 and t2 == n2:
        return 1
    if dp[t1][t2][c1][c2] != -1:
        return dp[t1][t2][c1][c2]
    else:
        a = solve(t1+1,t2,c1+1,0)
        b = solve(t1,t2+1,0,c2+1)
        dp[t1][t2][c1][c2] =(a+b)%(10**8)
        return dp[t1][t2][c1][c2] 
print(solve(0,0,0,0))