t = int(input())
for _ in range(t):
    x, y, z = map(int, input().split())
    if x == y and x >= z:  # a > b, c
        print('YES')
        print(x, z, z)
    elif x == z and x >= y:  # b > a, c
        print('YES')
        print(x, y, y)
    elif y == z and y >= x:  # c > a, b
        print('YES')
        print(y, x, x)
    else:
        print('NO')
    