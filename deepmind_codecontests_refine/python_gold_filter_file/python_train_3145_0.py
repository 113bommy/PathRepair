n = int(input())
a = list(map(int, input().split()))
me = a.index(-1)
if me == n - 1:
    print(0)
    exit()
for i in range(me + 1):
    a[i] = 0
dp = [[0] * n for _ in range(2)]
opt = [[0] * n for _ in range(2)]
dp[1][n - 1] = a[n - 1]
if n - 1 <= me + 1:
    ans = a[n - 1]
for i in range(2, 22):
    if 2 ** i > n:
        break
    s = i & 1
    t = s ^ 1
    l, r = n // 2 ** (i - 1) - 1, n - i + 1
    pl, pr = n // 2 ** (i - 2) - 1, n - i + 2
    opt[s][pr - 1] = dp[t][pr - 1]
    for j in range(pr - 2, pl - 1, -1):
        opt[s][j] = min(opt[s][j + 1], dp[t][j])
    for j in range(pl - 1, l - 1, -1):
        opt[s][j] = opt[s][j + 1]
    for j in range(r - 1, l - 1, -1):
        dp[s][j] = opt[s][j + 1] + a[j]
    if l <= me + 1:
        ans = min(dp[s][l:r])
print(ans)