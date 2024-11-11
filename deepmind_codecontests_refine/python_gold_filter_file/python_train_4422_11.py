n=int(input())
a=[int(x) for x in input().split()] 
print(n-1)
for i in range(n-1):
    m=n-1-a[::-1].index(min(a[i:]))
    print(i,m)
    a[i],a[m]=a[m],a[i]
