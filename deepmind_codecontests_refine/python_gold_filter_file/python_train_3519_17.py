n, k = map(int, input().split())
v = list(map(int, input().split()))

ans = 0
for i in range(n+1):
    for j in range(n+1):
        if i + j <= k and i + j <= n:
            g = v[:i] + v[n-j:]
            g.sort()
            for l in range(min(k-i-j, i+j)+1):
                ans = max(ans, sum(g[l:]))

print(ans)
