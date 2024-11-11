t = int(input())
for e in range(t):
    n,q = map(int,input().split())
    A = [*map(int,input().split())]
    for i in range(q):
        r, l = map(int,input().split())

    dp = [0, 0] #max with even army, max with odd army
    for i in range(n):
        a = A[i]
        if i>0:
            dp[0] = max(dp[0], dp[1]-a)
        dp[1] = max(dp[1], dp[0]+a)
    print(max(dp))
