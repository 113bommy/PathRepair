n, m = map(int, input().split())
if m >= n:
    print(n)
else:
    n -= m
    l, r = 0, n
    while l < r:
        mid = (l + r) // 2
        if (1 + mid) * mid // 2 >= n:
            r = mid
        else:
            l = mid + 1
    print(l + m)