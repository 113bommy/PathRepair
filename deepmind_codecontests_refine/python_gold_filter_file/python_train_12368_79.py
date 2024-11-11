w,h,x,y=map(int,input().split())
print(h*w/2, 1 if w==2*x and h==2*y else 0)