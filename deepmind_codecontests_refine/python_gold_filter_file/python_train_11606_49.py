n=int(input())
a=[1]*n
b=[1]*n
for i in range(n-1):
    for j in range(1,n):
        b[j]=a[j]+b[j-1]
    a=b.copy()
print(a[-1])
        