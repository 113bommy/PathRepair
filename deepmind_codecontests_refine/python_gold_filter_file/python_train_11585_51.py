for _ in range(int(input())):    
    n,m = map(int,input().split())
    
    if(n<m):
        if((n-m)%2 ==0):
            print(2)
        else:print(1)
        
    else:
        if(m==n):print(0)
        elif((m-n)%2==0):
            print(1)
        
        else:
            print(2)
            