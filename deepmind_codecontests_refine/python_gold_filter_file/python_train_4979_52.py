x, y = map(int, input().split())

if x + y == 15:
    print("+")
elif x * y == 15:
    print("*")
else:
    print("x")