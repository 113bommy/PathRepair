n, m = input().split()
n = int(n)
m = int(m)
ans = 1
a = list(map(int, input().split()))

if n > m:
    print(0)
else:
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            ans *= abs(a[i] - a[j])
            ans %= m

    print(ans)
