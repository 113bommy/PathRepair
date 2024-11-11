n=int(input())
a=list(map(int,input().split()))[:n]
for i in range(len(a)):
    while a.count(a[i])>1 and a[i]>0:
        if a[i]<0:
            break
        a[i]=a[i]-1
bh=sum(a)
print(bh)
