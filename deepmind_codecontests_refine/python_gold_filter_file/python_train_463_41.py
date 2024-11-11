r,x,y,x1,y1 = map(int,input().split())
dist = ((x-x1)**2 + (y-y1)**2)**0.5
print(-int(-dist//(2*r)))