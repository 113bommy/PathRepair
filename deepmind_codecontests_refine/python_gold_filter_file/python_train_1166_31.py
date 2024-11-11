a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if e<f:
    t=min(b,c,d)
    print(f*t+min(a,d-t)*e)
else:
    t=min(a,d)
    print(e*t+min(b,c,d-t)*f)