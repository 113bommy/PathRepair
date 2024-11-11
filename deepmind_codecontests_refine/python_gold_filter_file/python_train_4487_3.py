n = int(input())
a = sorted(map(int, input().split()))

best = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n])
for i in range(1, n):
    best = min(best, (a[n + i - 1] - a[i]) * (a[2 * n - 1] - a[0]))
print(best)