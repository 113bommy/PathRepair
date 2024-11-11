n=int(input())
l=list(map(int,input().split()))
if n==1:
    print(1,1)
    print(0)
    print(1,1)
    print(0)
    print(1,1)
    print(-l[0])
else:
    print(1,1)
    print(-l[0])
    l[0]=0
    print(2,n)
    for i in range(1,n):
        print((l[i]%n)*(n-1),end=' ')
        l[i]+=(l[i]%n)*(n-1)
        
    print()
    print(1,n)
    for i in range(0,n):
        
        print(-l[i],end=' ')
        
    
    
