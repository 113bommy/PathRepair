t,T,a,A,b,B=map(int,open(0).read().split())
x,y=(b-a)*t,(A-B)*T
if y-x==0:
 r="infinity"
else:
 s,t=divmod(x,y-x)
 r=max(0,s*2+(t!=0))
print(r)