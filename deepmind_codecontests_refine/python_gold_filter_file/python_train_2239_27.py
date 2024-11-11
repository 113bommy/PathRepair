x, y, z = input().split()
x = int(x)
y = int(y)
z = int(z)
a = x + y + z
if 2 * (x + y) < a:
    a = 2*(x+y)
if 2*(min(x, y)+z) < a:
    a = 2*(min(x, y)+z)
print(a)
