n,ak,bk=map(int,input().split())
k=ak+bk
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[0]*n
for i in range(n):
    c[i]=abs(a[i]-b[i])
c.sort()
x=0
coo=0
for i in range(k):
    c.sort()
    if c[n-1]==0:
        coo+=1
    c[n-1]=max(0,c[n-1]-1)
count=0
for i in range(n):
    count+=c[i]**2
print(count+coo%2)
