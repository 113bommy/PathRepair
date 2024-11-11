for _ in range(int(input())):
    n=int(input())
    if n%2==0:
        a=n//2-1
        b=n//2
        c=1
        print(a,b,c)
    else:
        
        x=(n-3)//2
        if x%2!=0:
            a=x
            b=x+2
            c=1
            print(a,b,c)
        else:
            a=(n-1)//2-2
            b=(n-1)//2+2
            c=1
            print(a,b,c)
            
        