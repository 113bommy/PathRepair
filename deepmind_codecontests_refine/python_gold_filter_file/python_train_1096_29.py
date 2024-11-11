n=int(input())
l=list(map(int,input().split()))
a=min(l)
b=max(l)
if(a==l[0] or b==l[0] or a==l[n-1] or b==l[n-1]):
    print(n-1)
else:
    a1=abs((n-1)-l.index(a))
    a2=abs(l.index(a))
    b1=abs((n-1)-l.index(b))
    b2=abs(l.index(b))
    print(max(a1,a2,b1,b2))
