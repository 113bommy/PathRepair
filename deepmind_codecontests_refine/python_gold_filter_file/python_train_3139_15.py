h,n=map(int,input().split())
l1=list(map(int,input().split()))
x=sum(l1)
y=h
t=0
m=0
f=0
for item in l1:
    f+=item
    m=min(m,f)
if x<0:
    t=t+(max(h+m,0))//(abs(x))*n
    h=h+(t//n)*x
    while h>-1*m:
        h+=x
        t+=n
    for item in l1:
        h+=item
        t+=1
        if h<=0:
            break
    print(t)
else :
    for item in l1:
        h+=item
        t+=1
        if h<=0:
            break
    if h>0:
        print(-1)
    else :
        print(t)