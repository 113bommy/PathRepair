a,b,c,x,y = map(int,input().split())
ya=min(a+b,2*c)
s=min(x,y)
if x>y:
    n=x-y
    k=a
else:
    n=y-x
    k=b
print(ya*s+n*min(k,2*c))
