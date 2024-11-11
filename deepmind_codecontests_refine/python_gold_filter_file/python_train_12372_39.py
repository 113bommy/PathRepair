n = int(input())
a = [[int(i) for i in input().split()] for _ in range(n)]

d = [a[i][:] for i in range(n)]
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j],d[i][k] + d[k][j])

ans = 0
for i in range(n):
    for j in range(n):
        if a[i][j] > d[i][j]:
            ans = -2
            break
        for k in range(n):
            if i == k or j == k: continue
            if d[i][j] == d[i][k] + d[k][j]: break
        else:
            ans += d[i][j]
    else:
        continue
    break

ans //= 2
print(ans)