n=int(input())
for i in range(n):
    a=list(map(int, input().split()))
    c=0
    if(a[1]<1 and a[2]<2):
        print("0")
    else:
        if(a[1]>=(a[2]//2)):
            c=c+((a[2]//2)*3)
            a[1]=a[1]-(a[2]//2)
        else:
            c=c+(a[1]*3)
            a[1]=0
        if(a[0]>=(a[1]//2)):
            c=c+((a[1]//2)*3)
        else:
            c=c+(a[0]*3)
        print(c)