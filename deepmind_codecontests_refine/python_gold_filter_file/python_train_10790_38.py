l,r,a=map(int,input().split())
large=max(l,r)
small=min(l,r)
x=large-small
if x>=a:
    print((small+a)*2)
else:
    y=large+int((a-x)/2)
    print(2*y)