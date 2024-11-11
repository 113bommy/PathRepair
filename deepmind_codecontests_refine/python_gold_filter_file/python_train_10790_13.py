l,r,a=input().split()
l=int(l)
r=int(r)
a=int(a)
if l>0 and r>0 and a>0:
    if l==r:
        if a%2==0:
            s=(l+r+a)
            print(s)
        else:
            s=(l+r+a-1)
            print(s)
    elif l==r and l==a and a==r:
        s=(l+r+a)
        if s%2==0:
            print(s)
        else:
            print(s-1)
    elif r>=(l+a):
        s=(l+a)
        print(s*2)
    elif l>=(r+a):
        s=(r+a)
        print(s*2)
    elif (r<=(l+a) and l<=(r+a) and a<(l+r)) or (a>=(l+r) and l<=(r+a) and r<=(l+a)):
        s=(l+r+a)
        if s%2==0:
            print(s)
        else:
            print(s-1)
    elif a<l and a<r:
        if r>=(a+l):
            s=(a+l)
            print(s*2)
        elif l>=(a+r):
            s=(a+r)
            print(s*2)
elif (l==0 and r>0 and a>0):
    if a>=r:
        s=(a+r)
        if s%2==0:
            print(s)
        else:
            print(s-1)
    else:
        s=2*r
        print(s)
elif (r==0 and l>0 and a>0):
    if a>=l:
        s=(a+l)
        if s%2==0:
            print(s)
        else:
            print(s-1)
    else:
        s=(2*l)
        print(s)
elif a==0:
    if l<=r:
        s=(2*l)
        print(s)
    else:
        s=(2*r)
        print(s)
elif (l==0 and r==0 and a>0):
    if a%2==0:
        s=a
        print(s)
    else:
        s=(a-1)
        print(s)
elif (l==0 and a==0 and r>0) or (l>0 and r==0 and a==0):
    print("0")

        
    
    