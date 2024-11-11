n = int(input())
a = list(map(int, input().split()))
R, L = {}, {}
for i in range(n):
    if a[i] not in L:
        L[a[i]] = i
    R[a[i]] = i

dp = [0] * (n + 1)
for i in range(n):
    dp[i] = dp[i - 1]
    if R[a[i]] != i:
        continue
    s = 0
    l = L[a[i]]
    for j in range(i, -1, -1):
        if R[a[j]] <= i:
            if R[a[j]] == j:
                s ^= a[j]
            l = min(l, L[a[j]])
            if j == l:
                dp[i] = max(dp[i], dp[j - 1] + s)
        else:
            break

print(dp[n - 1])