px, py, vx, vy = map(int, input().split())
if (px <= vx and py <= vy) or px+py <= max(vx, vy):
    print("Polycarp")
else:
    print("Vasiliy")
