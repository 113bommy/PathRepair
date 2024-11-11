r,x,y,xx,yy=map(int,input().split())
l=((x-xx)**2+(y-yy)**2)**0.5
print(-int(-l//(2*r)))
