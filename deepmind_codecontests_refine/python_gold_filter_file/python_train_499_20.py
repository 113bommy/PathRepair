a,b,c,x,y=map(int,input().split())
c=min(c*2,a+b)
ans=min(x,y)*c
if x>y:ans+=min(a,c)*(x-y)
else:ans+=min(b,c)*(y-x)
print(ans)