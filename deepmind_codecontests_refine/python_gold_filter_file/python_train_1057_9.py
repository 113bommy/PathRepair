
a,b,c=map(int,input().split())
d=a//c
e=b//c
f=a%c
z=b%c
f,z=sorted([f,z])
y=f-(f+z)%c if f+z>=c else 0
x=d+e
x+=1 if y else 0
print(x,y)