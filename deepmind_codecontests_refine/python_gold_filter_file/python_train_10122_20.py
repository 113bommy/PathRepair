n = int(input())
for i in range(n):
    a,b = list(map(int,input().split()))
    c = 0
    if a == b:
        c = 0
    elif a > b:
        if a%2 == 0:
            if b%2 == 0:
                c = 1
            else:
                c = 2
        else:
            if b%2 == 0:
                c = 2
            else:
                c = 1
    else:
        if a%2 == 0:
            if b%2 == 0:
                c = 2
            else:
                c = 1
        else:
            if b%2 == 0:
                c = 1
            else:
                c = 2
    print(c)
                