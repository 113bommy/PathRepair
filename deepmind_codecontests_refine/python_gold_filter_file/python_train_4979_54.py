[a,b]=[int(i) for i in input().split()]
if a*b==15:
    print("*")
elif a+b==15:
    print("+")
else:
    print("x")
