x,y=input().split()
x=int(x)
y=int(y)
a=input().split()
b=input().split()
z=int(input())
c=list()
r=0
while r<z:
    c.append(input())
    r=r+1
for s in c:
 s=int(s)-1
 l=s%x
 m=s%y
 print(a[l]+b[m])
