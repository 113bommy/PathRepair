minx=10**10 
maxx=-10**10 
miny=10**10 
maxy=-10**10 
n=int(input())
for i in range(n):
    x,y=map(int,input().split())
    minx=min(minx,x)
    maxx=max(maxx,x)
    miny=min(miny,y)
    maxy=max(maxy,y)
a=max(maxx-minx,maxy-miny)
print(a*a)