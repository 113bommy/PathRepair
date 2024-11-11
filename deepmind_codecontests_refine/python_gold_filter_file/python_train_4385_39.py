x, y, z, t1, t2, t3 = map(int, input().split())
s = abs(x - y) * t1
e = (abs(x - z) * t2) + t3 + t3 + (abs(x - y) * t2) + t3
if e <= s:
    print("YES")
else:
    print("NO")
