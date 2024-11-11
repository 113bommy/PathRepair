for _ in range(int(input())):
    n = int(input())
    add = 0
    p = 1
    ansreal =0

    while ansreal  < n :
        add = 2*p -1


        ansreal = ansreal + add

        p += 1

    if p == 1 :
        print(p)
    else:
        print(p-1)