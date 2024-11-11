n, k = map(int, input().split())
a = list(map(int, input().split()))
c = 0
for i in range(1, n):
    if k - a[i - 1] > a[i]:
        c += k - a[i - 1] - a[i]
        a[i] = k - a[i - 1]
print(c)
print(*a)