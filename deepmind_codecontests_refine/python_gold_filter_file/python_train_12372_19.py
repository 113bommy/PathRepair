n = int(input())
a = [list(map(int,input().split())) for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(i,n):
        if i==j:
            continue
        dp = 10**9+1
        for k in range(n):
            if k==j or k==i:
                continue
            dp = min(dp,a[i][k]+a[k][j])
        if a[i][j]<dp:
            ans += a[i][j]
        elif a[i][j]>dp:
            print(-1)
            exit()
print(ans)