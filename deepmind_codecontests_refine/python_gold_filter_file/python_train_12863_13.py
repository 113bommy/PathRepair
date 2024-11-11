z, r = map(int, input().split())

x = z

while (x % 10) and (x % 10 - r):
    x += z

print(x // z)