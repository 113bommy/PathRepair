ax, ay, bx, by, cx, cy = map(int, input().split())
if (bx - ax) ** 2 + (by - ay) ** 2 == (bx - cx) ** 2 + (by - cy) ** 2 and (ax - bx)*(cy - by) - (ay - by)*(cx - bx) != 0:
    print('Yes')
else:
    print('No')