for _ in range(int(input())):
    n,m=map(int,input().split())
    if(n<2):
        print(0)
    elif(n>2):
        print(2*m)
    else:
        print(m)