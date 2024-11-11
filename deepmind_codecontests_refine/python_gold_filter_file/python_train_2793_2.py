k = int(input())
a = list(map(int, input().split()))
l, r = 0, 10 ** 15
while r - l > 1:
    m = (l + r) // 2
    t = m
    for x in a:
        m = m // x * x
    if m <= 2:
        l = t
    else:
        r = t
l2, r2 = 0, 10 ** 15
while r2 - l2 > 1:
    m = (l2 + r2) // 2
    t = m
    for x in a:
        m = m // x * x
    if m < 2:
        l2 = t
    else:
        r2 = t
if l < r2:
    print(-1)
else:
    print(r2, l)
