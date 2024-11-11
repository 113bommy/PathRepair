n=int(input())
a=list(map(int,input().split()))
c=0
d=0
z=a.count(-1)
for i in range(n):
    if(a[i]==-1):
        if(d>0):
            d-=1
            c+=1
    else:
        d+=a[i]
print(z-c)        
