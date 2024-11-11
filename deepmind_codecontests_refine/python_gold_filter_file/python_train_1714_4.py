a=list(map(int,input().split()))
a.sort()
isk=sum(a)//3*3
if a[2]>(a[0]+a[1])*2:
    isk-=a[2]-(a[0]+a[1])*2
print(max((isk+2)//3,0))
