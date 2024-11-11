n = input()
n = n[-1::-1]
for i in n:
    if int(i) >=5:
        print("-O|", end="")
        i = int(i)-5
    else:
        print("O-|", end="")
    print("O"*int(i)+"-"+"O"*(4-int(i)))
