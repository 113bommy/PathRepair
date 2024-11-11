h,n=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(n)]

max_a=max(a for a,_ in ab)
dp = [0] * (h+max_a)

for i in range(0,h+max_a):
    if i==0:
        dp[i]=0
    else:
        dp[i]=min(dp[i-a]+b for a,b in ab)
print(min(dp[h:]))