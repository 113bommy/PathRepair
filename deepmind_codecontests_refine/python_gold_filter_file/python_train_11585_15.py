for i in range(int(input())):
    a,b = map(int,input().split())
    if a == b:
        print(0)
    elif a < b:
        if b - a <= 10:
            print(1)
        elif (b-a) % 10 == 0:
            print((b-a)//10)
        else:
            print(1 + (b-a)//10)
    else:
        if a-b <= 10:
            print(1)
        elif (a-b) % 10 == 0:
            print((a-b)//10)
        else:
            print(int(1 + (a-b)//10))