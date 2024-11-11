x = int(input())
if 30 <= x <= 100:
    if x % 4 == 1:
        print(0, "A")
    elif x % 4 == 2:
        print(1, "B")
    elif x % 4 == 3:
        print(2, "A")
    elif x % 4 == 0:
        print(1, "A")
else:
    print("Wrong value of x")