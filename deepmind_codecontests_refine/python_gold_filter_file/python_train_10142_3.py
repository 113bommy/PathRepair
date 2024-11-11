#code
a,b = map(int,input().split())
x=y=z=0

for i in range(1,7):
    if(max(a-i,i-a)<max(b-i,i-b)):
        x+=1
    elif(max(a-i,i-a)==max(b-i,i-b)):
        y+=1
    else:
        z+=1

print(x,y,z)