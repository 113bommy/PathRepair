for i in range(int(input())):
    a, b = map(int, input().split(' '))
    if b == 0:
        print(1)
    elif a == 0:
        print(1/2)
    else:
        if 4*b<=a:
            print(1-2*b*b/(2*a*b))
        else:
            print(1-((b+b-a/4)*a/2)/(2*a*b))
