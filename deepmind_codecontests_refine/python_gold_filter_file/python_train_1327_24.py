x, y = [int(i) for i in input().split()]
z = 7-max(x, y)
a = 6
if z == 2 or z == 4:
    z //= 2
    a //= 2
if a % z == 0:
    a //= z
    z = 1

print(str(z) + '/' + str(a))
