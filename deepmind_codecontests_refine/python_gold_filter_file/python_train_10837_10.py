s = input()
l = len(s)
if len(s) % 20 == 0:
    print(len(s)//20, 20)
    g = 0
    for i in range(len(s)//20):
        d = 0
        while d!=20:
            print(s[g],end="")
            g+=1
            d+=1
        print()
else:
    k = len(s) // 20
    z = 0
    while (l + z) % (k + 1) != 0:
        z += 1
    print(k + 1, (l + z) // (k + 1))
    h = z // (k + 1)
    f = z - z // (k + 1)
    g = 0
    for i in range(k + 1):
        d = 0
        if f != 0:
            print("*", end = "")
            d += 1
            f -= 1
        print("*" * h, end = "")
        d += h
        while d != (l + z) // (k + 1):
            print(s[g],end = "")
            g += 1
            d += 1
        print()