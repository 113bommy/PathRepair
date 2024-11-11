T=int(input())
while T>0:
    n,k=map(int,input().split())
    b=k//(n-1)*n
    a=k%(n-1)
    if k%(n-1)==0:
        print(a+b-1)
    elif n>k:
        print(k)
    else:
        print(a+b)
    T-=1
    
    