a, b = map(int, input().split())
c = 0
while a <= b:
    c += 1
    b //= 2
print(c)