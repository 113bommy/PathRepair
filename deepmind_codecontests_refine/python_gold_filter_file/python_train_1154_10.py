n, m = map(int, input().split())
a = list(map(int, input().split()))
ans = [a[0] // m]
for i in range(1, n):
    a[i] += a[i-1]
    if i == 1:
        ans.append(a[i]//m - ans[0])
    else:
        ans.append(a[i]//m - a[i-1]//m)
print(*ans, sep=' ')