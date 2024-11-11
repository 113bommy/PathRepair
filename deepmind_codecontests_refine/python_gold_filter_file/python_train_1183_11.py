n, k = map(int, input().split())
a = sorted(map(int, input().split()))
print ((n >= k and (n == k or a[n - k] != a[n - k - 1])) and str(a[n - k]) + " " + str(a[n - k]) or "-1")
