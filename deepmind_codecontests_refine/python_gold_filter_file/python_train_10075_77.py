n,s=map(int,input().split()) 
a=list(map(int,input().split()))
d=[[0]*(s+1) for _ in range(n+1)]
d[0][0]=1
for j in range(0,s+1):
    for i in range(1,n+1):
        d[i][j]=2*d[i-1][j]
        if a[i-1]<=j:
            d[i][j]+=d[i-1][j-a[i-1]]
        d[i][j]=d[i][j]%998244353
print(d[n][s])