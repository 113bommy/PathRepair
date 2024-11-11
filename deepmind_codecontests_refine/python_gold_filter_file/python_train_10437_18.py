t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split(" ")))
    
    for i in range(n):
        if i%2==0:
            a[i]=-1*abs(a[i])
        else:
            a[i]=abs(a[i])
    
    print(*a)
        