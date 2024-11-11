n, m = map(int, input().split())

ans = 0

for _ in range(m):
    x, d = map(int, input().split())
    if d > 0:
        ans += n*x + d*((n*(n-1))//2)
    else:
        k = n // 2
        if n % 2 == 1:
            ans += n*x + d*k*(k+1)
        else:
            ans += n*x + d*k*k

print(ans/n)