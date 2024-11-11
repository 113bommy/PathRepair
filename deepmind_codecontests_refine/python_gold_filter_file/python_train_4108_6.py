def f(n,cnt):
    dp= [0]*(n+1)
    dp[1]=cnt[1]
    for i in range(2,n+1):
        dp[i]=max(dp[i-1],dp[i-2]+i*cnt[i])
        #print("######"+str(dp[i]))
    return(dp[n])
n=int(input())
ar=list(map(int,input().split()))
cnt= [0]* (1000000)
for a in ar:
    cnt[a]+=1
ans=f(100000,cnt)
print(ans)