t=int(input())
while t>0:
    n,k=map(int,input().split())
    x=k//(n-1)
    rem = k-x*(n-1)
    
    if rem==0:
        print(n*x-1)
    else:
        print(n*x+rem)
    t-=1