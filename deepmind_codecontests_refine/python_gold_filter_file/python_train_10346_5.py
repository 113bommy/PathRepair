n,k=map(int,input().split())
l,d=[],[]
for u in range(n):
    x,y=map(int,input().split())
    l.append(x)
    d.append(y)
m=-(10**9)
for i in range(n):
    if(d[i]>=k):
        s=l[i]-(d[i]-k)
    else:
        s=l[i]
    if(s>m):
        m=s
print(m)
