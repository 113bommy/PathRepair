for _ in range(int(input())):
    a, b, c = list(map(int, input().split()))
    if c <= a:
        print(-1, b)
    elif c < a * b:
        print(1, b)
    else:
        print(1, -1)
