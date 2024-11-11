n,m=map(int,input().split())

a=[]
b=[]
for i in range(m):
    x,y=input().split()
    a.append(x)
    b.append(y)

c=list(input().split())

for i in range(n):
    
    if len(a[a.index(c[i])])<=len(b[a.index(c[i])]):
        print(a[a.index(c[i])],end=" ")
    else:
        print(b[a.index(c[i])],end=" ")
