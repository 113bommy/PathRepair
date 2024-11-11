for _ in range(int(input())):
    a, b = map(int, input().split())

    if a == b:
        print(0)
    elif a < b:
        if (b - a) % 2 == 1:
            print(1)
        else:
            print(2)
    else:
        if (b - a) % 2 == 1:
            print(2)
        else:
            print(1)