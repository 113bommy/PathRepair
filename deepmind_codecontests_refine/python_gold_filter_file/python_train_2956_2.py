def bs(l, h):
    while l < h:
        m = (l + h + 1) // 2
        if a[m] < i:
            l = m
        else:
            h = m - 1
    return l

n, m = map(int, input().split())
c, t = map(int, input().split())
l = c * t
a = [0]
for _ in range(n - 1):
    c, t = map(int, input().split())
    a.append(l)
    l = a[-1] + c * t
b = map(int, input().split())
for i in b:
    print(bs(0, n - 1) + 1)