n, k = map(int, input().split())
l = 0
r = n + 1
while r - l > 1:
    m = (l + r) // 2
    if m * (m + 1) // 2 - (n - m) > k:
        r = m
    else:
        l = m
print(n - l)