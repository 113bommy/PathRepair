s=list(map(int,input().split()))
m=0
a=sorted(s)
if(a[0]+a[1]>a[2]):
    print(m)
else:
    print(a[2]+1-a[0]-a[1])