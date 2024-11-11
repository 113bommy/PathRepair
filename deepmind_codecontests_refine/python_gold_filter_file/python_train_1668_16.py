x, y = [int(n) for n in input().split()]
if (x < y):
    x, y = y, x
while y:
    (x, y) = (y, x % y)
print(x)

