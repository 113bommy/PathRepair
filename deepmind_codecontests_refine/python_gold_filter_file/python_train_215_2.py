rd = lambda: map(int, input().split())
n, s = rd()
a = sorted(rd())
n >>= 1
print(abs(a[n] - s) + sum(max(0, x - s) for x in a[:n]) + sum(max(0, s - x) for x in a[n + 1:]))
