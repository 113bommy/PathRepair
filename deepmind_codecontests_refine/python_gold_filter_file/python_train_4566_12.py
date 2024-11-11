w,a,b=map(int,input().split())
if b+w<a:print(a-b-w)
else:print(max(0,b-a-w))