
    
x = int(input())
y = input()
r = y.count('R')
g = y.count('G')
b = y.count('B')

if r>=1 and g>=1 and b>=1:
    print("BGR")
elif r>=1 and g>=1:
    if r==1 and g==1:
        print("B")
    elif r==1:
        print("BR")
    elif g==1:
        print("BG")
    else:
        print("BGR")
elif r>=1 and b>=1:
    if r==1 and b==1:
        print("G")
    elif r==1:
        print("GR")
    elif b==1:
        print("BG")
    else:
        print("BGR")
elif b>=1 and g>=1:
    if b==1 and g==1:
        print("R")
    elif b==1:
        print("BR")
    elif g==1:
        print("GR")
    else:
        print("BGR")
elif r>=1:
    print("R")
elif g>=1:
    print("G")
else:
    print("B")
