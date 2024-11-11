w,h,x,y,r = map(int,input().split())
print(['No','Yes'][(r<=x<=w-r)*(r<=y<=h-r)])
