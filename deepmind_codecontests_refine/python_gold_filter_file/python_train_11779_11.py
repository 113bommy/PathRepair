import sys
x,y,z = input().split()
a,b,c= input().split()
x=int(x)
y=int(y)
z=int(z)
a=int(a)
b=int(b)
c=int(c)
if (a-x<0):
    print("NO")
    sys.exit(0)
a = a-x
if a+b<y:
    print("NO")
    sys.exit(0)
b = b+a - y
if b+c<z:
    print("NO")
    sys.exit(0)
print("YES")