k=input().split()
n,m,k=int(k[0]),int(k[1]),int(k[2])
a=[0]*1000001
c=input().split()
for i in range(n):
    a[int(c[i])]=1
b=0
p=0
for i in range(m):
    if a[i]==1:
        p+=1
    if p==k:
        a[i]=0
        p-=1
        b+=1
for i in range(m,1000001):
    if a[i-m]==1:
        p-=1
    if a[i]==1:
        p+=1
    if p==k:
        a[i]=0
        p-=1
        b+=1
print(b)