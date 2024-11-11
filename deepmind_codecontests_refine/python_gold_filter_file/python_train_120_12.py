for i in range(int(input())):
    a,b,c = map(int,input().split())
    k = 0
    while b >= 1 and c >= 2:
        b -= 1
        c -= 2
        k += 3
    while a >= 1 and b >= 2:
        a -= 1
        b -= 2
        k += 3
    print(k)