n=int(input())
for i in range(0,n):
    a=list(map(int,input().split()))
    l=a[0]
    r=a[1]
    if l%2==1:
        if (r-l)%2==0:
            print((int((-l-r)/2)))
        else:
            print(int(((-r-l+1)/2)+r))
    else:
        if (r-l)%2==0:
            print(int(((l+r)/2)))
        else:
            print(int((l-r-1)/2))
