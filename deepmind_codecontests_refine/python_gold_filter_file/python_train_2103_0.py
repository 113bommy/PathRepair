import math
t = int(input())
i = 0
while i < t:
    mass = list(input().split())
    a = int(mass[0])
    b = int(mass[1])
    c = int(mass[2])
    d = int(mass[3])
    k = int(mass[4])

    pen = str(math.ceil(a/c))
    pensil = str(math.ceil(b/d))
    if int(pen) + int(pensil) > k:
        print (-1)
    else:
        print(pen + " " + pensil)

    i += 1