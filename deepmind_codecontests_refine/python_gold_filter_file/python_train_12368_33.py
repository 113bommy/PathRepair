w,h,x,y=map(int,input().split())
huku=0
if w/2==x and h/2==y:
  huku=1
print(w*h/2,huku)