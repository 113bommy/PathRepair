n, k = map(int, input().split())

if k == 0 or k == n:
    mn = 0

else:
    mn = 1

if 3 * k <= n:
    mx = 2 * k

else:
    mx = n - k

print(mn, mx)