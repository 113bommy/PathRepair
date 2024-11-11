c=1
while 1:
    W=int(input())
    if W==0:break
    dp=[0]*(W+1)
    for i in range(int(input())):
        v,w=map(int, input().split(','))
        for j in range(W,w-1,-1):
            if dp[j]<dp[j-w]+v:dp[j]=dp[j-w]+v
    for i in range(W+1):
        if dp[W]==dp[i]:break
    print('Case %d:\n%d\n%d'%(c,dp[W],i))
    c+=1