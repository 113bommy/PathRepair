a = input().split()
a1 = int(a[0])
a2 = int(a[1])
x = 0
while a2 > a1 or a2 == a1:
    x += 1
    a2 *= 2
    a1 *= 3

print(x)





