h,n=map(int,input().split())
AB=[list(map(int,input().split())) for i in range(n)]

max_A=max(AB)[0]+h
DP=[float("inf")]*max_A
DP[0]=0

for i in range(h):
    for a,b in AB:
        DP[i+a]=min(DP[i+a],DP[i]+b)

print(min(DP[h:]))