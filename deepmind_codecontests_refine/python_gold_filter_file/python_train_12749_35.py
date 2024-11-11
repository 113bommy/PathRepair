from decimal import Decimal
n,l=[int(i) for i in input().split()]
a=sorted([int(i) for i in input().split()])
ma=2*(a[0]-0)
for i in range(n-1):
    if(a[i+1]-a[i]>ma):
        ma=a[i+1]-a[i]
ma=max(ma,2*(l-a[-1]))
print(round(Decimal(ma)/Decimal(2),10))
