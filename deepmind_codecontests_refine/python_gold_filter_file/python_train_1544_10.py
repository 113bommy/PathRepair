n, m = map(int, input().split())
x = list(map(int, input().split()))
x.reverse()
cum = [0] * (n+1)
for i in range(n):
    cum[i+1] = cum[i] + x[i]
mincost = 2 * n * m + 5 * cum[n]
for k in range(1,n):
    cost = m * (n + k)
    for i in range(n//k):
        cost += (cum[(i+1)*k] - cum[i*k]) * max(5, 3 + i*2)
    cost += (cum[n] - cum[n//k * k]) * max(5, 3 + n//k*2)
    mincost = min(mincost, cost)
print(mincost)