a=int(input())
x=0
y=0
z=0
for i in range(a):
    b=list(input().split(" "))
    first=b[0]
    second=b[1]
    third=b[2]
    x += int(first)
    y +=int(second)
    z +=int(third)
#print(x,y,z)

if x==0 and y==0 and z==0:
    print("YES")
else:
    print("NO")
