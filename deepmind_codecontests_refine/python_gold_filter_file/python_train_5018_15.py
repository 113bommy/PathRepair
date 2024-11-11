for _ in range(int(input())):
    a , b = map(int,input().split())
    if (a>b):
        x=a-b
        x5=x//5
        x55=x%5
        x2=x55//2
        x=x55%2
        print(x5+x2+x)
    elif (b>a):
        x=b-a
        x5=x//5
        x55=x%5
        x2=x55//2
        x=x55%2
        print(x5+x2+x)
    else:
        print(0)