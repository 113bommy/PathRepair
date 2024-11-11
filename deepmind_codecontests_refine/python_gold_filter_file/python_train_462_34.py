r,x,y,x1,y1=map(int,input().split())
dist=((x1-x)**2 + (y1-y)**2)**0.5

if dist==0:
    print(int(dist))
elif dist<2*r:
    print(int(1))
else:
    if dist%(2*r)==0: print(int(dist//(2*r)))
    else:print(int(dist//(2*r)+1))