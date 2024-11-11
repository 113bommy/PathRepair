l,r,a=map(int,input().split(' '))
if l<r:
    x=r-l
    if a<x:
        l=l+a
        print(2*l)
    else:
        a=a-x
        r=r+a//2
        print(2*r)
elif l==r:
    r=r+a//2
    print(r*2)
else:
    x=l-r
    if a<x:
        r=r+a
        print(2*r)
    else:
        a=a-x
        l=l+a//2
        print(2*l)
