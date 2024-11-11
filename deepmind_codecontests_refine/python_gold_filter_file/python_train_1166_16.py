
a=int(input())
b=int(input())
c=int(input())
d=int(input())

p=int(input())
q=int(input())
b=min(b,c)
if q>p:
    p,q=q,p
    a,b=b,a

if d<a:
    print(d*p)
else:
    d-=a
    print(a*p+min(d,b)*q)
