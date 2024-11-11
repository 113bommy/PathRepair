r,d=list(map(int,input().split()))
n=int(input())
a=[]
b=[]
for _ in range(n):
    x,y,z=list(map(int,input().split()))
    m=(x**2+y**2)**0.5
    a.append(m-z)
    b.append(m+z)
y=0
for i in range(n):
    if a[i]>=(r-d) and b[i]<=r:
        y+=1
print(y)