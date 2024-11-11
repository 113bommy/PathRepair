n,k,*a=map(int,open(0).read().split())
l=[]
for i in range(n):
    t=0
    for j in range(i,n):
        t+=a[j]
        l.append(t)
for i in range(40,-1,-1):
    j=2**i
    t=[]
    for x in l:
        if x&j:
            t.append(x)
    if len(t)>=k:
        l=t
a,*b=l
for t in b:
    a&=t
print(a)