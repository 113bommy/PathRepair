a = list(map(int, input().split()))
w,h,x,y,r = a

if(r<=x<=w-r and r<=y<=h-r):
    print("Yes")
else:
    print("No")