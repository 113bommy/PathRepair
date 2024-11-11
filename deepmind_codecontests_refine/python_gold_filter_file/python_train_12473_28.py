n=int(input())
a=[int(s) for s in input().split()]
b=[0]*n
b[1]=abs(a[0]-a[1])
for i in range(2,n):
    b[i]=min(b[i-1]+abs(a[i]-a[i-1]),b[i-2]+abs(a[i]-a[i-2]))
print(b[n-1])  