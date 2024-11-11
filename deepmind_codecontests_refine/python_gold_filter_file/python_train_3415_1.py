n,l=map(int,input().split())
r=l+n-1
m=r if r<0 else l
s=(l+r)*n//2
print(s if l*r<=0 else s-m)