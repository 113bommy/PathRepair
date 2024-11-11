n, k = map(int, input().split())
if (k == 0):
    print(0, 0)
else:
    mn = min(1, n - k)
    mx = min(2 * k, n - k)
    print(mn, mx)