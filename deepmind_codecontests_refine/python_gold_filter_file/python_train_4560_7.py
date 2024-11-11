n,k,*a=map(int,open(0).read().split())
z=sorted(a[:n]),sorted(a[n:])[::-1]
o=10**12
g=-1
while o-g>1:
 m,l=o+g>>1,k
 for a,f in zip(*z):l-=max(0,a-m//f)
 if l<0:g=m
 else:o=m
print(o)