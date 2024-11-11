from math import sqrt
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    first = a - b
    second = a + b
    if first != 1:
        print('NO')
    else:
        f = False
        for i in range(2, int(sqrt(second)) + 1):
            if second % i == 0:
                f = True
                break
        if f:
            print('NO')
        else:
            print('YES')