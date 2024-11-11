def checker(a,n):
    a.sort()
    x=1
    y=1
    z=1
    zz=[a[n-1]]
    for i in range(0,n-1):
        if a[i]==a[i+1]:
            x+=1
        else:
            z+=1
            zz.append(a[i])
            if y<=x:
                y=x
                x=1
            else:
                x=1
    if y<=x:
        y=x
    return y,z,zz
t=int(input())
for i in range(0,t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    x,z,zz=checker(a,n)
    if z<=k:
        print(n*k)
        for j in range(0,n):
            for l in range(0,len(zz)):
                print(zz[l],end=' ')
            if z<k:
                for m in range(z,k):
                    print(max(zz),end=' ')
            else:
                continue
        print()
    else:
        print("-1")
