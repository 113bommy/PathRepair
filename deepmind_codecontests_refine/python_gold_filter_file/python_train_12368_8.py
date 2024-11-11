w,h,x,y=map(int,input().split())
print(w*h/2,1 if w==x*2 and h==y*2 else 0)