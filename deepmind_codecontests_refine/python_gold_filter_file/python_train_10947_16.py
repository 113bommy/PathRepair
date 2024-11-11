for caso in range(int(input())):
    n = int(input())
    cont = 0
    while n != 1:
        if n % 2 == 0:
            n //= 2
            cont += 1
        elif n % 3 == 0:
            n = 2*n//3
            cont += 1
        elif n % 5 == 0:
            n = 4*n//5
            cont += 1
        else:
            cont = -1
            break
        # print(n)
    print(cont)
