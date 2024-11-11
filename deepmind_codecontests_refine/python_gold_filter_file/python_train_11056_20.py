for i in range(int(input())):
    x, y = (int(x) for x in input().split())
    if x == 1 and x != y:
        print('NO')
    elif x <= 3 and y > 3:
        print('NO')
    else:
        print('YES')
