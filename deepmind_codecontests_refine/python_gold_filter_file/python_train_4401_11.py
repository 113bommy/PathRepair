for _ in range(0,int(input())):
    a=int(input())
    b=list(map(int,input().split()))
    if len(set(b))==1:
        print(a)
    else:
        print(1)