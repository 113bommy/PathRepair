a, b, c = map(int, input().split())
mx = max(a, b, c)
print(max(0, 2 * mx - (a + b + c) + 1))