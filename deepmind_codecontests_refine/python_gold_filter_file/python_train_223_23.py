for case in range(int(input())):
    a,b,t = map(int,input().split())
    if t%3==0:
        print(a)
    elif t%3==1:
        print(b)
    else:
        print(a^b)