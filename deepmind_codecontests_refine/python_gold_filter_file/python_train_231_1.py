for _ in range(int(input())):
    n = int(input())
    if n==1:
        print(0)
    elif n%3 == 0:
        te = 0
        tem = n
        while tem%3 == 0:
            tem=tem//3
            te+=1
        te1 = 0
        while tem%2 == 0:
            tem=tem//2
            te1+=1
        if te1>te or tem != 1:
            print(-1)
        else:
            print(2*te-te1)
    else:
        print(-1)

