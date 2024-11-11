n, k = map(int, input().split())
a = list(map(int, input().split()))

l, r = 1, n
while l <= r:
    m = (l + r) // 2
    id1 = m * (m - 1) // 2
    id2 = m * (m + 1) // 2
    if k <= id1:
        r = m - 1
    elif k > id2:
        l = m + 1
    else:
        print(a[k - m * (m - 1) // 2 - 1])
        break
