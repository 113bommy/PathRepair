n,m=map(int,input().split())
a=[1]*(n*2)
a[0]=a[n-1]=a[n]=a[n*2-1]=0
for i in range(m):
    x,y=map(int,(input().split()))
    a[x-1]=a[y+n-1]=0
if(n%2 and a[n+n//2] and a[n//2]):a[n//2]=0
print(sum(a))
