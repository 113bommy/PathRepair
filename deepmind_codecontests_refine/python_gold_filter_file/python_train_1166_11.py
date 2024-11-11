a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
f=int(input())
if e>=f:
    if a>d:
        print(str(d*e))
    else:
        print(str(a*e+min(d-a,b,c)*f))
else:
    if min(b,c)>d:
        print(str(d*f))
    else:
        print(str(min(b,c)*f+min(d-min(b,c),a)*e))