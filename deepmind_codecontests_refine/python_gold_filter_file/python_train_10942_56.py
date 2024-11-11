for i in range(int(input())):
    s, a, b, c=map(int,input().split())
    x=s//c
    y=x+((x//a)*b)
    print(y)