for i in range(int(input())):
    a=input()
    n=len(a)
    d=n
    for j in range(10):
        e=[0]*(9-j)
        c=0
        g=0
        h=[0]*(9-j)
        for k in range(n):
            y=int(a[k])
            if y==j:
                if c>0:
                    for l in range(9-j):
                        e[l]+=f[l]
                f=[0]*(9-j)
                c+=1
            elif c>0 and y>j:
                z=y-j-1
                if f[z]==0:
                    f[z]=1
            elif c==0 and y>j:
                z=y-j-1
                if h[z]==0:
                    h[z]=1
        if c>0:
            for l in range(9-j):
                e[l]+=f[l]
        c0=c
        for k in range(9-j):
            if h[k]==1 and c0>0 and f[k]==0:
                e[k]+=1
            c=max(c,2*e[k])
        d=min(d,n-c)
    print(d)