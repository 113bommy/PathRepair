a=list(map(int,input().split()))

if a[3]>2*a[2] or 2*a[3]<a[2] or a[3]>=a[1]:
    print("-1")
else:
    print(2*a[0],2*a[1],min(2*a[2],2*a[3]))