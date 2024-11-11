n = int(input())

if n % 2 == 0:
    print("NO")
else:
    n -= 1
    x = 1
    y = (n // 2) - 1
    if x <= y:
        print("{} {}".format(x, y))
    else:
        print("NO")
