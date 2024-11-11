n,m,k=map(int,input().split())
b=[0]+list(map(int,input().split()))
rem=[float('inf') for i in range(m)]
rem[0]=k
curr=0
ans=0
for i in range(1,n+1):
    curr+=b[i]
    ans=max(ans,curr-min(rem))
    rem[i%m]=min(rem[i%m],curr)
    rem[i%m]+=k





print(ans)


