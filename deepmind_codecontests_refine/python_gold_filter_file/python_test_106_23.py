for _ in range(int(input())):
    n=int(input())
    if n==1:print(1)
    else:
        arr=[]
        x=2
        for i in range(1,n+1):
            arr.append(x)
            x+=1
        print(*arr)