x2 = int(input())
n = x2
vis = [False for i in range(n+1)]
f = [0 for i in range(n+1)]
for i in range(2, n+1):
    if not vis[i]:
        for j in range(i+i, n+1, i):
            vis[j] = True
            f[j] = i
ans = x2
for i in range(x2 - f[x2] + 1, x2+1):
    ans = min(ans, i - f[i] + 1)
print(ans)
