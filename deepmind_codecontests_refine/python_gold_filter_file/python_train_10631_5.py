n = int(input())
m = 10 ** 6 - 1
a = [int(i) % m for i in input().split()]
l = 0
s = 0
print(n + 1)
for i in range(n - 1, -1, -1):
    a[i] = (a[i] + s) % m
    k = (m - n + i) - a[i]
    if k < 0:
        k += m
    s += k
    s %= m
    a[i] += k
    a[i] %= m
    print(1, i + 1, k)
print(2, n, m)
