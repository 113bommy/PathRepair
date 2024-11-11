l,r,a=map(int,input().split())
d=min(l,r)*2
l-=d//2
r-=d//2
k=min(max(l,r),a)
d+=k*2
a-=k
print(d+a//2*2)