l, r, a = map(int, input().strip().split())

if l > r:
    l, r = r, l
d = r - l
if d >= a:
    res = l + a
else:
    res = r + (l + a - r) // 2
print(2 * res)
