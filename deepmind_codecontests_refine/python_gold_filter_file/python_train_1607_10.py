x1, y1, z1 = map(int, input().split())
x2, y2, z2 = map(int, input().split())
answer = (x2 - x1) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2 < 3

print("YES" if answer else "NO")
