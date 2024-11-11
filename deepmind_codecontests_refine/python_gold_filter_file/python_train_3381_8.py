a, b, s = [abs(int(i)) for i in input().split()]
if s < a + b:
    print("No")
else:
    if (a + b - s) % 2 == 0:
        print("Yes")
    else:
        print("No")