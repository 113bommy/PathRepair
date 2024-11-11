s,k=list(map(int,input().split()))
a=[1]
i=0
while s>a[-1]:
    if i==0:
        a.append(1)
    else:
        a.append(2*a[-1]-int(a[-k-1] if i>=k else 0))
    i+=1
b=[]
s0=s
while s>0:
    l,r=-1,i+1
    while r-l>1:
        m=(l+r)//2
        if a[m]>=s:
            r=m
        else:
            l=m
    r=min(i,r)
    while a[r]>s:
        r-=1
    s-=a[r]
    b.append(a[r])
if len(b)==1:
    b.append(0)
print(len(b))
print(*b)