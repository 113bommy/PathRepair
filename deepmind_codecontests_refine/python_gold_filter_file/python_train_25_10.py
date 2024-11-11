t=int(input())

for _ in range(t):
    n=int(input())
    f=[]
    for i in range(n):
        f.append(str(input()))
    a=f[1][0]
    b=f[0][1]
    c=f[-1][-2]
    d=f[-2][-1]
    
    if a==b:
        if c==d:
            if a!=c:
                print(0)
            else:
                print(2)
                print(1,2)
                print(2,1)
        else:
            print(1)
            if c==a:
                print(n,n-1)
            else:
                print(n-1,n)
    else:
        if c==d:
            print(1)
            if a==c:
                print(2,1)
            else:
                print(1,2)
        else:
            print(2)
            if a==c:
                print(2,1)
                print(n-1,n)
            else:
                print(1,2)
                print(n-1,n)
                
                