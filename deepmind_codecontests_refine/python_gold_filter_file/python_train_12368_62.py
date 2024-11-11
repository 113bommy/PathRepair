w,h,x,y = map(int,input().split())
ans = 0
if x*2==w and y*2==h:ans=1
print(w*h/2,ans)