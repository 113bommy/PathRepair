N,Ma,Mb=map(int,input().split())
abc = list(list(map(int,input().split()))for i in range(N))
DP = [[[10**9]*(10*N+1) for i in range(10*N+1)]for i in range(N+1)]
DP[0][0][0] = 0
for i in range(N):
    for j in range(10*N+1):
        for k in range(10*N+1):
            if j >= abc[i][0] and k >= abc[i][1]:
                DP[i+1][j][k] = min(DP[i][j][k],DP[i][j-abc[i][0]][k-abc[i][1]]+abc[i][2])
            else:
                DP[i+1][j][k] = DP[i][j][k]
ans = 10**9
for i in range(1,10*N//max(Ma,Mb)+1):
    ans = min(DP[-1][i*Ma][i*Mb],ans)
if ans >= 10**8:
    print(-1)
else:
    print(ans)