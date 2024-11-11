r,g,b=map(int,input().split())
a,d,c=0,0,0
a=r//3+b//3+g//3
if(r and g and b):r,g,b=r-1,g-1,b-1;a=max(a,r//3+b//3+g//3+1)
if(r and g and b):r,g,b=r-1,g-1,b-1;a=max(a,r//3+b//3+g//3+2)
print(a)