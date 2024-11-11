x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if(x<=a and (y<=(a+b-x)) and z<=((a+b+c)-(x+y))):
    print('YES')
else:
    print('NO')