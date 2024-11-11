n=int(input())
a=list(map(int, input().split()))
a.sort()
max=a[0]
for i in range (n):
    if a[i]>=0:
        if float(a[i]**(1/2))%1!=0.0:
            if a[i]>max:
                max=a[i]
    else:
        if a[i]>max:
            max=a[i]
print(max)            
        