def check(mid):
    global n, m
    return n + m * mid - (m + mid + 1) * (m + mid + 2) // 2 + m * (m + 1) // 2 <= 0


n, m = map(int, input().split())
if m + 1 >= n:
    print(n)
else:
    ans = m + 1
    l = 0
    r = n + 1
    while (r - l > 1):
        mid = (r + l) // 2
        if check(mid):
            r = mid
        else:
            l = mid
    ans += r
    print(ans)