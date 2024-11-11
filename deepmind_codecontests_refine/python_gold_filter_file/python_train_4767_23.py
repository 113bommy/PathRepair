k, q = map(int, input().split())
d = list(map(int, input().split()))
nxm = [list(map(int, input().split())) for i in range(q)]
for n, x, m in nxm:
    prev = x
    ans = 0
    cur = 0
    for i in range(k):
        prev += (d[i] % m) * ((n + k - i  - 2) // k)
        if d[i] % m == 0:
            cur += ((n + k - i  - 2) // k)
    print(n - prev // m + x // m - cur - 1)