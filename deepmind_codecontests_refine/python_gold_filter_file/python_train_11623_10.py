p,m,s,h=map(int,input().split())
t=max(s,h)
if t>2*min(s,h) or h>=m:
    print(-1)
else:
    a=2*h+1
    ap,am=max(p,a)+1,max(m,a)
    print(ap,am, t)
