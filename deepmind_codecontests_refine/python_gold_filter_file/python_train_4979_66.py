a, b = map(int, input().split())

aplusb = a + b
ab = a * b

if aplusb == 15:
    print("+")
elif ab == 15:
    print("*")
else:
    print("x")
