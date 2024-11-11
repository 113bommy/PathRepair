w,h,x,y=map(int,input().split())
ans=w*h/2
s=0
if w==x*2 and h==y*2:s=1
print(ans,s)