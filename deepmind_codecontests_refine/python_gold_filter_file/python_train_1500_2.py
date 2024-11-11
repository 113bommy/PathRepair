n = int(input())
x1, y1, x2, y2 = map(int, input().split())
l, r, u, d = x1, x2, y2, y1
s = (x2 - x1) * (y2 - y1)
for i in range(n - 1):
    x1, y1, x2, y2 = map(int, input().split())
    s += (x2 - x1) * (y2 - y1)
    l = min(l, x1)
    r = max(r, x2)
    u = max(u, y2)
    d = min(d, y1)
if r - l == u - d and (r - l) * (u - d) == s:
    print('YES')
else:
    print('NO')
