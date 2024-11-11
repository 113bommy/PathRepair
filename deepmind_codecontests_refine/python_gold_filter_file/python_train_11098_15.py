alph = "v<^>"
pos = input()
n = int(input())
if n % 2 == 0:
    print("undefined")
else:
    if (alph.find(pos[0]) - alph.find(pos[2])) % 4 - n % 4 == 0:
        print("ccw")
    else:
        print("cw")
