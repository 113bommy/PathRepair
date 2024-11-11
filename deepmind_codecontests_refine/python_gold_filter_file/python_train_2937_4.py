for _ in range(1):
    n,m=map(int,input().split()) 
    if n==1 and m==1:
        print(0)
        break
    if n==1:
        for i in range(1,m+1):
            print(n+i,end=" ")
        print()
        break
    
    for i in range(1,n+1):
        for j in range(1,m+1):
            print((m+i)*j,end=" ")
        print()