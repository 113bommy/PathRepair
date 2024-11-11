t = int(input())




for _ in range(t):
    a, b = map(int, input().split())
    if a == b:
        print(0)
    else:
        if a > b:
            if (a - b) & 1:
                print(2)
            else:
                print(1)
        else:
            if (b - a) & 1:
                print(1)
            else:
                print(2)