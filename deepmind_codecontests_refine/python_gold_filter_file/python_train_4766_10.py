X, Y = map(int, input().split())
if Y%2==1 or 4*X<Y or 2*X>Y:
    print("No")
else:
    print("Yes")


