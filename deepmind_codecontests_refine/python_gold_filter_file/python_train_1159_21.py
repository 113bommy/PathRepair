n=int(input())
a=[int(x) for x in input().split()]
a.sort()
b=[0]*n
x=0
for i in range(0,n,2):
    b[x]=a[i]
    x+=1
x=n-1
for i in range(1,n,2):
    b[x]=a[i]
    x-=1
print(*b)
        
