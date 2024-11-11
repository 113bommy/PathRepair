n,m=map(int,input().split(' '))
a=[]
b=[]
for i in range(n):
    a.append(list(map(int,input().split(' '))))
for i in range(n):
    b.append(list(map(int,input().split(' '))))
for i in range(n):
    j=i
    k=0
    c=[]
    d=[]
    while j>=0 and k<m:
        c.append(a[j][k])
        d.append(b[j][k])
        j-=1
        k+=1
    c.sort()
    d.sort()
    for j in range(len(c)):
        if c[j]!=d[j]:
            print("NO")
            exit(0)
for i in range(m):
    j=n-1
    k=i
    c=[]
    d=[]
    while j>=0 and k<m:
        c.append(a[j][k])
        d.append(b[j][k])
        j-=1
        k+=1
    c.sort()
    d.sort()
    for j in range(len(c)):
        if c[j]!=d[j]:
            print("NO")
            exit(0)
print("YES")
