for _ in range(int(input())):
    a,b,n=map(int,input().split())
    n%=3
    if n==0:
        print(a)
    elif n==1:
        print(b)
    else:
        print(a^b)