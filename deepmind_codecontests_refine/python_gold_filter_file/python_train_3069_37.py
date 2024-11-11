w = 0
b = 0
for i in range(8):
    s = input()
    for i in range(len(s)):
        if (s[i] == "Q"):
            w += 9
        elif (s[i] == "R"):
             w += 5
        elif (s[i] == "B"):
            w += 3
        elif (s[i] == "N"):
            w += 3
        elif (s[i] == "P"):
            w += 1
        elif (s[i] == "q"):
            b += 9
        elif (s[i] == "r"):
             b += 5
        elif (s[i] == "b"):
            b += 3
        elif (s[i] == "n"):
            b += 3
        elif (s[i] == "p"):
            b += 1
if (b > w):
    print("Black")
elif (w > b):
    print("White")
else:
    print("Draw")
            

