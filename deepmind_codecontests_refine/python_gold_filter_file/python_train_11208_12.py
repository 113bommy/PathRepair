a = input()
b = input() + " "
c = ""
d = 0
for i in b:
    if i == "x":
        c = c + i
    else:
        if len(c) >= 3:
            d = d + (len(c) - 2)
        c = ""
print(d)
