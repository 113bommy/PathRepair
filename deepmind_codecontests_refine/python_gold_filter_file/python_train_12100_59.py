for _ in range(int(input())):
    x, y, a, b = map(int, input().split())

    time = (y-x) // (a+b)

    if ((y-x) % (a+b)) == 0:
        print(time)
    else:
        print("-1")
