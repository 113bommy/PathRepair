for _ in range(int(input())):
    a,b,c,d=map(int,input().split())
    if b==c:
        print(b,b,b)
    else:
        print(b,b+c-b,c)