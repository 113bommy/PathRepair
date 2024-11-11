n, m = map(int, input().split())
L = [w * (w - 1) // 2 + (n - w) * (n - w + 1) // 2 for w in [1, max(1, n//2), (n+1)//2, n]]
ans = 0
for i in range(m):
    x, d = map(int, input().split())
    ans += max([(n * x + d * y) for y in L])
print(ans/n)
