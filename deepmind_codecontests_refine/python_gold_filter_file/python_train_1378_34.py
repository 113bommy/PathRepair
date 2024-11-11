for _ in range(int(input())):
    x = int(input())
    if x % 2 == 0:
        print(x >> 1, x >> 1)
    else:
        print(1, x-1)