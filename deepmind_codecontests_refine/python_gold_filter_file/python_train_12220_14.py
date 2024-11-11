x,y=map(int,input().split())
z=max(abs(x),abs(y))
c=(z-1)*4
if x==z and y>-z+1 and y<=z:
    c+=1
elif x<z and x>=-z and y==z:
    c+=2
elif x==-z and y<z and y>=-z:
    c+=3
elif y==-z and x>-z and x<=z+1:
    c+=4
print(max(0,c))