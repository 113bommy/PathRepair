w,h,x,y=map(int,input().split())
ans=0
if w/2==x and h/2==y:
  ans=1
print(w*h/2,ans)
