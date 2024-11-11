s = list(input())
e = list(input())

horiz = ord(s[0])-ord(e[0])
verti = int(s[1])-int(e[1])

if horiz >= 0 and verti >= 0:
    if horiz >= verti:
        print(horiz)
        for i in range(verti):
            print("LD")
        for i in range(horiz-verti):
            print("L")
    else:
        print(verti)
        for i in range(horiz):
            print("LD")
        for i in range(verti-horiz):
            print("D")
elif horiz >= 0 and verti < 0:
    verti *= -1
    if horiz >= verti:
        print(horiz)
        for i in range(verti):
            print("LU")
        for i in range(horiz-verti):
            print("L")
    else:
        print(verti)
        for i in range(horiz):
            print("LU")
        for i in range(verti-horiz):
            print("U")
elif horiz < 0 and verti < 0:
    verti *= -1
    horiz *= -1
    if horiz >= verti:
        print(horiz)
        for i in range(verti):
            print("RU")
        for i in range(horiz-verti):
            print("R")
    else:
        print(verti)
        for i in range(horiz):
            print("RU")
        for i in range(verti-horiz):
            print("U")
elif horiz < 0 and verti >= 0:
    horiz *= -1
    if horiz >= verti:
        print(horiz)
        for i in range(verti):
            print("RD")
        for i in range(horiz-verti):
            print("R")
    else:
        print(verti)
        for i in range(horiz):
            print("RD")
        for i in range(verti-horiz):
            print("D")
