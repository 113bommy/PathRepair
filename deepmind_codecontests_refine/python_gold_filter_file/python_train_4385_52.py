x, y, z, t1, t2, t3 = map(int, input().split())
foot = abs(x - y) * t1
lift = (abs(x - z) * t2 + abs(x - y) * t2 + t3 * 3)
if lift <= foot:
    print("YES")
else:
    print("NO")
