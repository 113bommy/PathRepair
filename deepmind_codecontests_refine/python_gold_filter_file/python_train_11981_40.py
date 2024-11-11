W,H,x,y,r=map(int,input().split())
print(['No','Yes'][(r<=x<=W-r)*(r<=y<=H-r)])
