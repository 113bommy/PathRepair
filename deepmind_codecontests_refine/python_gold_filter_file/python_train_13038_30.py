t=int(input())
for _ in range(t):
    arr=list(map(int,input().split(" ")))
    n=arr[0]
    m=arr[1]
    n,m=min(n,m),max(n,m)
    if n==1 and m==1:
        print(1)
    elif n==1 and m%2==0:
        print(m//2)
    elif n==1 and m%2!=0:
        print(m//2+1)
        
    elif n%2==0 and m%2==0:
        print(n*(m//2))
    elif n%2!=0 and m%2!=0:
        print(n*((m-1)//2)+((n+1)//2) )
        
    elif n%2==0 and m%2!=0:
        print(n*((m-1)//2)+(n//2) ) 
        
    elif n%2!=0 and m%2==0:
        print(n*(m//2) )