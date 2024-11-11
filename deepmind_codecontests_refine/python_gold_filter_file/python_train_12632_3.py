n=int(input())
a=[2*[0]for i in range(0,n)]
for i in range(0,n):
    a[i]=list(map(str,input().split()))
na=[0]*2001
for i in range(0,2001):
    na[i]=[]
c=[0]*(n+1)
for i in range(0, n):
    ind=int(a[i][1])
    if a[i][0]=='win':
        na[ind].append(i+1)
        c[i+1]=-1
    else:
        c[i+1]=ind
dp=[0]*(n+1)
for i in range(1,n+1):
    dp[i]=dp[i-1]
    if c[i]!=-1 and len(na[c[i]])>0:
        l=0
        r=len(na[c[i]])
        while(r-l>1):
            mid=(r+l)/2
            mid=int(mid)
            if na[c[i]][mid]>=i:
                r=mid
            else:
                l=mid
        if na[c[i]][l]>=i:
            continue
        if dp[i]<2**c[i]+dp[na[c[i]][l]-1]:
            dp[i] = 2 ** c[i] + dp[na[c[i]][l] - 1]
print(dp[n])
# Sun Mar 22 2020 14:22:06 GMT+0300 (MSK)
