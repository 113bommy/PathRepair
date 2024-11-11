w,h,x,y=map(int,input().split())
if x==w/2 and y==h/2:
    a=1
else:
    a=0
print(w*h/2,a)