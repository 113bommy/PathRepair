n=int(input())
m=n*2
a=list(map(int,input().split()))
if n==1:
    print(0)
else:
    a.sort()
    m1=(a[m-1]-a[m//2])*(a[m//2-1]-a[0])
    m2=(a[m-1]-a[0])
    for i in range(1,n):
        if a[i+n-1]-a[i]<m2:
            m2=a[i+n-1]-a[i]
    m2*=a[m-1]-a[0]
    print(min(m1,m2))
