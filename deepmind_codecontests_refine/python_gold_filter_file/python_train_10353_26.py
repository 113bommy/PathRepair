a=list(map(int,input().split()))
n=int(a[0])
v=int(a[1])
p=0
k=0
d=[]
for i in range(n):
    c=0
    b=[]
    b=list(map(int,input().split()))
    k=int(b[0])
    l=[1]*(k+1)
    for j in range(1,k+1):
        l[j]=int(b[j])
    for m in range(1,k+1):
        if l[m]<v:
            c=c+1
    if c>=1:
        p=p+1
        d.append(i+1)
print(p)
for i in range(len(d)):
    print(d[i],end=" ")
        
