(x, y, z) = list(map(int, input().split()))
(a, b, c) = list(map(int, input().split()))

if a >= x:
    a -= x
    if (a+b) >= y:
        a -= y
        if (a+b+c) >= z:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')
else:
    print('NO')



