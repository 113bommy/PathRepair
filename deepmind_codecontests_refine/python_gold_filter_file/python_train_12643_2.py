x,y=map(int,input().strip().split())
n=int(input())
n=n%6
if n==3:
    print((y-x)%1000000007)
elif n==1:
    print(x%1000000007)
elif n==2:
    print(y%1000000007)
elif n==4:
    print((-x)%1000000007)
elif n==5:
    print((-y)%1000000007)
elif n==0:
    print((x-y)%1000000007)

    

    
    
