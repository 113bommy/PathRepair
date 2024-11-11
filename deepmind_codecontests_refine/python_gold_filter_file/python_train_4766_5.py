X, Y = map(int, input().split())
print("Yes" if 2 * X <= Y <= 4 * X and (Y % 2 == 0) else "No")