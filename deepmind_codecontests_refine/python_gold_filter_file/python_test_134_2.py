def hcfnaive(a,b):
    if(b==0):
        return a
    else:
        return hcfnaive(b,a%b)


t=int(input())
for i in range(t):
    n=int(input())
    a=[int(i) for i in input().split()]
    b,c=[],[]
    for j in range(n):
        if j%2==0:
            b.append(a[j])
        else:
            c.append(a[j])
    p=True
    q=True
    x=b[0]
    y=c[0]
    for j in range(1,len(b)):
        if b[j]==1:
            p=False
            break
        x=hcfnaive(x,b[j])
        if x==1:
            p=False
            break
    for j in range(1,len(c)):
        if c[j]==1:
            q=False
            break
        y=hcfnaive(y,c[j])
        if y==1:
            q=False
            break
    r,u=True,True
    if p==True:
        for j in range(len(c)):
            if c[j]%x==0:
                r=False
                break
    if q==True:
        for j in range(len(b)):
            if b[j]%y==0:
                u=False
                break
    if p==True and r==True:
        print(x)
    elif q==True and u==True:
        print(y)
    else:
        print(0)



