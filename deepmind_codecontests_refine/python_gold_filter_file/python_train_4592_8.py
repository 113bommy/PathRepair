from math import sqrt
t = int(input())
for i in range(t):
    a, b = [int(x) for x in input().split()]
    if a - b == 1:
        c = int(a + b)
        for j in range(2, int(sqrt(c)) + 1):
            if c % j == 0:
                print('NO')
                break
        else:
            print('YES')
    else:
        print('NO')