

n, m, k = map(int, input().split())

if k < n:
    print(k + 1, 1)
else:
    k -= n
    row = n - k // (m - 1)
    if (k // (m - 1)) % 2 == 0:
        col = 2 + k % (m - 1)
    else:
        col = m - k % (m - 1)
    print(row, col)
