t=int(input())
for _ in range(t):
    n=int(input())
    a=[]
    for i in range(1,n+1):
        a.append(i)
    if(n%2==0):
        for i in range(0,n,2):
            a[i],a[i+1]=a[i+1],a[i]
        print(*a,sep=' ')
    else:
        if(n==3):
            print('3 1 2')
        else:
            y=n-3
            for i in range(0,y,2):
                a[i],a[i+1]=a[i+1],a[i]
            for i in range(3):
                a.pop()
            a.append(n)
            a.append(n-2)
            a.append(n-1)
            print(*a,sep=' ')
