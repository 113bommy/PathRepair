n,m,k=input().split(" ")
n=int(n)
m=int(m)
k=int(k)
x1=(n*m)//k
x2=n*m-x1*(k-1)
x=1
y=1
z=0
for i in range(0,k-1):
    print(x1,end=" ")
    for j in range(0,x1):
        if z==0:
            print(x,y,end=" ")
            y+=1
        else:
            print(x,y,end=" ")
            y-=1
        if z==1 and y==0:
            y=1
            x+=1
            z=0
        if z==0 and y==m+1:
            y=m
            x+=1
            z=1
    print()
print(x2,end=" ")
for i in range(0,x2):
    if z==0:
        print(x,y,end=" ")
        y+=1
    else:
        print(x,y,end=" ")
        y-=1
    if z==1 and y==0:
        y=1
        x+=1
        z=0
    if z==0 and y==m+1:
        y=m
        x+=1
        z=1
print()