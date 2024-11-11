
a,b,c = map(int,input().split())
if a ==0 and b==0:
    if c ==0:
        print("-1")
    else:
        print("0")
    exit(0)
D = pow(b,2) -4*a*c
x = -b
y = pow(D,1/2)
z = 2*a
r = 0
if a ==0:
    print("1")
    print(-c/b)
    exit(0)
if D < 0:
    print(r)
    exit(0)
if D ==0:
    r = 1
    e1 = (x-y)/z
    print(r,e1)
else:
    r = 2
    e1 = (x+y)/z
    e2 = (x-y)/z
    if e2<e1:
        e1,e2 =e2,e1
    print(r,e1,e2)