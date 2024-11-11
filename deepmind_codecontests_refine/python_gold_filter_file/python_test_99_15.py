for _ in range(int(input())):
    x, n = map(int, input().split())
    if n == 0:
        print(x)
        continue
    m = n%4
    if x%2==0:
        if m == 1:
            print(x - n)
        elif m == 2:
            print(x+1)
        elif m == 3:
            print(x+n+1)
        else:
            print(x)
    else:
        if m == 1:
            print(x + n)
        elif m == 2:
            print(x-1)
        elif m == 3:
            print(x-n-1)
        else:
            print(x)