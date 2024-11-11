import cmath
x, y = map(int, input().split())

if x == 1 or y == 1:
    if x > y:
        print(">")
    elif x < y:
        print("<")
    else:
        print("=")
    exit(0)

a = float(str(cmath.log(x, 2))[1:-4]) * y
b = float(str(cmath.log(y, 2))[1:-4]) * x
if a > b:
    print(">")
elif a == b:
    print("=")
else:
    print("<")