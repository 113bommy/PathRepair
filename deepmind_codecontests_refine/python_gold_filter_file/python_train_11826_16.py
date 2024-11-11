n=int(input())
a=sorted(map(int,input().split()))
mi,k=100000000000,0
for i in range(1,n):
    if mi>a[i]-a[i-1]:
        mi=a[i]-a[i-1]
        k=1
    else:
        if mi==a[i]-a[i-1]:
            k+=1
print(mi,k)
