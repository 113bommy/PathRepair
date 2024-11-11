for _ in range(1):
    n=int(input())
    l=list(map(int,input().split()))
    dp=[0]*(10**6+1)
    for i in l:
        dp[i]=1
    for i in l:
        if dp[i]:
            for x in range(i*2,10**6+1,i):
                if dp[x]:
                    dp[x]=max(dp[x],dp[i]+1)
    print(max(dp))                
    