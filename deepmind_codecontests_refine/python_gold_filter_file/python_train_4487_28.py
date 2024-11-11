n = int(input())
a = list(map(int, input().split()))
a.sort()
mn = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n])
for i in range(1, n + 1):
    if i < n:
        mn = min(mn, (a[n + i - 1] - a[i]) * (a[2 * n - 1] - a[0]))
    else:
        mn = min(mn, (a[n + i - 1] - a[i]) * (a[i - 1] - a[0]))
print(mn)