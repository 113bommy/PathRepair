t=int(input())
for i in range(t):
    lt=list(map(int,input().split()))
    x,n=lt[0],lt[1]
    if(x%2==0 and n%2==0):
        if(n%4==0):
            print(x)
        else:
            print(x+1)
    elif(x%2==1 and n%2==0):
        if(n%4==0):
            print(x)
        else:
            print(x-1)
    elif(x%2==0 and n%2==1):
        if((n-1)%4!=0):
            print(n+1+x)
        else:
            print(x-n)
    else:
        if(n-1)%4==0:
            print(x+n)
        else:
            print(x-n-1)

        
    
    