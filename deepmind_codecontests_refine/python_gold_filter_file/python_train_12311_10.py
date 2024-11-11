t = int(input())

for i in range(t):
    a, b, c = map(int, input().split())

    first = second = 0

    if c < a:
        first = -1
        second = c
        print(first, second)
    elif c > a:
        if a * b < c:
            first = b - 1
            second = -1
        elif a * b > c:
            first = 1
            second = b
        else:
            first = 1
            second = -1
        print(first, second)
    else:
        print(-1, b)