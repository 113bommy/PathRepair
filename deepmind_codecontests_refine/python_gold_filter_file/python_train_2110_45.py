for i in range(int(input())):
    n=int(input())
    a=[]
    b=[1,2,3,6]
    for i in range(n+1):
        if i!=0:
            a.append(i)
    print(*range(1,n+1))
