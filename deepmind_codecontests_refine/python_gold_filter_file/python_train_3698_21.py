n = int(input())
s = input()

r,g,b = 0,0,0
for i in range(n):
    if s[i] == "R":
        r+=1
    if s[i] == "G":
        g+=1
    if s[i] == "B":
        b+=1

if r != 0 and g == 0 and b == 0:
    print("R")
elif r == 0 and g != 0 and b == 0:
    print("G")
elif r == 0 and g == 0 and b != 0:
    print("B")
elif r > 0 and g > 0  and b > 0:
    print("BGR")
elif (r > 1 and b > 1 and g == 0):
    print("BGR")
elif (r > 1 and b == 0 and g> 1):
    print("BGR")
elif r == 0 and b > 1 and g > 1:
    print("BGR")
elif r == 1 and g == 1 and b == 0:
    print("B")
elif r == 1 and g == 0 and b == 1:
    print("G")
elif r == 0 and g == 1 and b == 1:
    print("R")
else:
    if r > 1 and b + g == 1:
        print("BG")
    elif g > 1 and b + r == 1:
        print("BR")
    elif b > 1 and r + g == 1:
        print("GR")
    
