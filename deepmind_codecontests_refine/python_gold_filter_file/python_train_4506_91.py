for _ in range(int(input())):
    a, b, c = sorted(tuple(map(int, input().split())))
    if a + b >= c:
        print(1)
    else:
        print(c - a - b + 1)
