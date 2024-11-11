for _ in range(int(input())):
    n,s=map(int,input().split())
    if(n==1):
        print(0)
    elif(n==2):
        print(s)
    else:
        print(2*s)