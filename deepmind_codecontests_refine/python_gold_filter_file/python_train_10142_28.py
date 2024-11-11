a,b=list(map(int,input().split()))
x=0
y=0
z=0
for i in range(1,7):
    if abs(i-a)< abs(i-b):
        x=x+1
    elif  abs(i-a)> abs(i-b):
        y=y+1
    else:
        z=z+1
print(x,z,y)