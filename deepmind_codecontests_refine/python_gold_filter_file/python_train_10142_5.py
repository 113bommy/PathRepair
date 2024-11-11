a,b=map(int,input().split())
z,x,c=0,0,0
for i in range(1,7):
    if abs(a-i)<abs(b-i):
        z+=1
    elif abs(a-i)>abs(b-i):
        c+=1
    else:
        x+=1
print(z,x,c)