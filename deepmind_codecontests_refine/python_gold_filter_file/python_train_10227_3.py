for t in range(int(input())):
    n,k = map(int,input().split())
    if n == 1:
        if k == 1:
            print('YES')
        else:
            print('NO')
    elif k*k > n:
        print('NO')
    else:
        if n%2 == 0 and k == 1:
            print('NO')
        else:
            if n%2 == 0 and k%2 != 0:
                print('NO')
            elif n%2 != 0 and k%2 == 0:
                print('NO')
            else:
                print('YES')