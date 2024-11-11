w,h,x,y,r = map(int,input().split())

if 0<(x+r)<=abs(w) and 0<(y+r)<=abs(h):
    print("Yes")
else:
    print("No")