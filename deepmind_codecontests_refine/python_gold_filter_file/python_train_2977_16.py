n, k = map(int, input().split())
i, f = 2, []
while i * i <= n:
    while n % i == 0:
        f.append(i)
        n //= i
    i += 1
if n > 1:
    f.append(n)
if len(f) < k:
    print(-1)
else:
    for j in range(len(f) - k):
        f[j + 1] *= f[j]
    print(' '.join(map(str, f[-k:])))