n=int(input())
a=list(map(int,input().split()))
a=[0]+a
e=0
d=0
for i in range(1,n+1):
    if a[i]-a[i-1]>=0:
        if (a[i]-a[i-1])>e:
            d+=(a[i]-a[i-1])-e
            e=0
        else:
            e-=(a[i]-a[i-1])
    else:
        e+=(a[i-1]-a[i])
print(d)        
        
        