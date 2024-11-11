n, ans, m, s = int(input()), 0, 1000000007, [0]
a = sorted(map(int, input().split()))
for i in range(1, n):
    s.append((2 * s[i - 1] + a[i - 1]) % m)
    ans += ((pow(2, i, m) - 1) * a[i] - s[i]) % m
print(ans % m)