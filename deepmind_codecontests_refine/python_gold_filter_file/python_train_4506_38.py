for t in range(int(input())):
    a,b,c=map(int,input().split())
    d=[a,b,c]
    d.sort()
    a=d[0]
    b=d[1]
    c=d[2]
    print(b+c-a)