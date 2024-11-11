w,h,x,y=map(int,input().split())
a = 0
if(h==2*y and w ==2*x):
  a +=1
print(w*h/2,a)
