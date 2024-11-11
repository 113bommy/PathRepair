from sys import stdin

n, k, a, b = [int(stdin.readline()) for i in range(4)]
ans = 0

if k == 1:
    ans = a * (n - 1)
else:
    while n > 1:
        div, mod = divmod(n, k)
        if mod:
            ans += mod * a
            n -= mod
            if not n:
                ans -= a
        else:
            x1 = a * (n - div)
            ans += min(b, x1)
            n = div

print(ans)
