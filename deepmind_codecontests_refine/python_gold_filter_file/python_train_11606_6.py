n = int(input())
a = [[1]*n]*n
#print(a)
for j in range(1,n):
    for i in range(1,n):
        a[j][i]=a[j-1][i]+a[j][i-1]
print(a[n-1][n-1])
