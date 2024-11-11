a,b = map(int,input().split())
val = abs(a) +abs(b)
p =val*a//abs(a) 
q=0
x=0
y= val* b//abs(b)
if(p>0 ):
    print(q,y,p,x)  
else:
    print(p,q,x,y)