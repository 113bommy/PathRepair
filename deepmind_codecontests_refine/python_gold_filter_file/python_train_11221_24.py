H,N = map(int,input().split())
MAXH = H+10000
DP = [float("inf")]*MAXH
DP[0] = 0
for i in range(N):
    a,b = map(int,input().split())
    for j in range(MAXH):
        if j+a>MAXH-1:break
        DP[j+a] = min(DP[j+a],DP[j]+b)
print(min(DP[H:]))