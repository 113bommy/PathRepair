n,l = (int(i) for i in input().split())
d = (l-1)*n+(n+1)*n//2
if l<1: print(d+1-l-min(n,1-l))
else: print(d-l)