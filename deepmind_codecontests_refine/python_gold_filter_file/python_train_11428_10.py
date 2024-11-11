n,x,m=map(int,input().split())
l=[x]
c=1
d=-1
f=0
while(x>0 and c<n):
    g=(x*x)%m
    d=g
    if(g in l):
        f=1
        break
    l.append(g)
    x=g
    c+=1
s=sum(l)
if(f==1):
    r=l.index(g)
    o=(n-c)//(c-r)
    t=(n-c)%(c-r)
    s+=o*(sum(l[r:]))+sum(l[r:r+t])
print(s)
