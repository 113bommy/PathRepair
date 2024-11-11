for _ in range(int(input())):
    N,M=map(int,input().split())
    if(N==1):
        print(0)
    elif N==2:
        print(M)
    else:
        print(2*M)