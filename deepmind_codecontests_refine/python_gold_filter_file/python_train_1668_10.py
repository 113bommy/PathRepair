x, y = (int(s) for s in input().split())
while y > 0:
    x, y = y, x % y
print(x)