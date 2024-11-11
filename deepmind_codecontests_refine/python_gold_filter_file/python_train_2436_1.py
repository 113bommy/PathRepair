a, b = map(int, input().split())
s = input().strip()
c2d = dict()
c2d['U'] = (0, 1)
c2d['D'] = (0, -1)
c2d['L'] = (-1, 0)
c2d['R'] = (1, 0)
dx = dy = 0
for c in s:
    dx += c2d[c][0]; dy += c2d[c][1]

ans = not a and not b
x = 0; y = 0
for c in s:
    x += c2d[c][0]; y += c2d[c][1]    
    xx = a - x
    yy = b - y
    if ((xx % dx == 0 and xx // dx >= 0) if dx else not xx) and ((yy % dy == 0 and yy // dy >= 0) if dy else not yy) and (not dx or not dy or xx // dx == yy // dy):
        ans = True
print("Yes" if ans else "No")
