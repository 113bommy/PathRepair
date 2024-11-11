n,W=map(int,input().split())
sumv=0
v,w=[],[]
m=10**9
for i in range(n):
    a,b=map(int,input().split())
    w.append(a)
    v.append(b)
    sumv+=b
dp=[m]*(sumv+1)
dp[0]=0
for i in range(n):
    for j in range(sumv,v[i]-1,-1):
        dp[j]=min(dp[j],dp[j-v[i]]+w[i])
ans=0

for i in range(sumv+1):
    if dp[i]<=W:
        ans=i 
# print(dp)
print(ans)
