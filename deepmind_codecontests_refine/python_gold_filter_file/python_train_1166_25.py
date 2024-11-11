a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if(e<f):
    c1=min(b,c,d)*f
    c2=min(a,d-min(b,c,d))*e
    print(c1+c2)
else:
    c2=min(a,d)*e
    c1=min(b,c,d-min(a,d))*f
    print(c1+c2)
    