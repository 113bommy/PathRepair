D = int(input())
D = -D
D = D % 360
print((404 - D) // 90 if D > 45 else 0)
