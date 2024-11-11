n,k=map(int,input().split())
*h,=map(int,input().split())

dp=[0]*n
for i in range(1,n):
    dpmin=[]
    for j in range(max(0,i-k),i):
        dpmin.append(dp[j]+abs(h[i]-h[j]))
    dp[i]=min(dpmin)
print(dp[-1])
