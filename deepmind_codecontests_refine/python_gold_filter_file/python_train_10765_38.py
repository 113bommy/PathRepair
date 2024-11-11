n = input()
for i in n[::-1]:
    line = ""
    if int(i) >= 5:
        line+= "-O|"
    else:
        line += "O-|"
    a = int(i)%5
    line += "O"*a
    line += "-"
    line += "O"*(4-a)
    print(line)