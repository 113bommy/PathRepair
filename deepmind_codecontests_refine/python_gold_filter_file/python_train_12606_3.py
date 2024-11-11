n,m= map(int,input().split())
a1=[]
b1=[]
c=[]
for i in range(n):
    a,b= map(int,input().split())
    a1.append(a)
    b1.append(b)
if int(sum(b1))>m:
    print(-1)
elif int(sum(a1))<=m:
    print(0)
else:
    for i in range(n):
        j=a1[i]-b1[i]
        c.append(j)
    c.sort()
    c.reverse()
    k=sum(a1)
    d=0
    for i in range(n):
        k-=c[i]
        d+=1
        if k<=m:
            break
    print(d)
