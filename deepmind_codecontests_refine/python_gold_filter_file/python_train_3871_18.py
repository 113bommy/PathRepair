n, k = map(int, input().split())
a = sorted(map(int, input().split()))
if n < 2:
    print(a[0] + k)
    exit()
i = n // 2
while k >= (i - n // 2 + 1) * (a[i + 1] - a[i]):
    diff = (i - n // 2 + 1) * (a[i + 1] - a[i])
    if diff:
        k -= diff
        a[n // 2 : i + 1] = [a[i + 1]] * (i - n // 2 + 1)
    i += 1
    if i > n - 2:
        break
print(a[n // 2] + k // (i - n // 2 + 1))