a, b = input().split()
a = int(a)
b = int(b)
y = 0
while a <= b:
    a *= 3
    b *= 2
    y += 1
print(y)