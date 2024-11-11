for _ in range(int(input())):
    b, w = map(int, input().split())

    if b <= w:
        if w > 3 * b + 1:
            print('NO')
        else:
            print('YES')
            x = 2
            y = 3
            for i in range(b):
                print(x + 2 * i, y)

            for j in range(min(w, b+1)):
                print(x - 1 + 2 * j, y)

            if 2 * b + 1 >= w > b + 1:
                for j in range(min(w - b-1, b)):
                    print(x + 2 * j, y - 1)

            if 3 * b + 1 >= w > 2 * b + 1:
                for j in range(b):
                    print(x + 2 * j, y - 1)
                for j in range(w - 2*b - 1):
                    print(x + 2 * j, y + 1)
    else:
        if b > 3 * w + 1:
            print('NO')
        else:
            print('YES')
            x = 2
            y = 2
            for i in range(w):
                print(x + 2 * i, y)

            for j in range(min(b, w + 1)):
                print(x - 1 + 2 * j, y)

            if 2 * w + 1 >= b > w + 1:
                for j in range(min(b - w - 1, w)):
                    print(x + 2 * j, y - 1)

            if 3 * w + 1 >= b > 2 * w + 1:
                for j in range(w):
                    print(x + 2 * j, y - 1)
                for j in range(b - 2 * w - 1):
                    print(x + 2 * j, y + 1)
