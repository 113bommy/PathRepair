for _ in range(int(input())):
    n,x = map(int,input().split())
    dp=[0]*(n+1)
    for i in range(n-1):
        a,b = map(int,input().split())
        dp[a]+=1
        dp[b]+=1
    if(dp[x]<2 or n%2==0):
        print("Ayush")
    else:
        print("Ashish")        