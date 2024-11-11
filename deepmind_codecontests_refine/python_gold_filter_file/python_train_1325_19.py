Y, W = map(int, input().split())
if 7 - max(Y, W) <= 0:
    print("0/1")
elif 7 - max(Y, W) <= 1:
    print("1/6")
elif 7 - max(Y, W) <= 2:
    print("1/3")
elif 7 - max(Y, W) <= 3:
    print("1/2")
elif 7 - max(Y, W) <= 4:
    print("2/3")
elif 7 - max(Y, W) <= 5:
    print("5/6")
elif 7 - max(Y, W) <= 6:
    print("1/1")
else:
    print("0/6")