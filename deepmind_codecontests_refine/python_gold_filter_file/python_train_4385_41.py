x, y, z, t1, t2, t3 = list(map(int, input().split()))
print("YES" if 3 * t3 + abs(x - z) * t2 + abs(x - y) * t2 <= abs(x - y) * t1 else "NO")