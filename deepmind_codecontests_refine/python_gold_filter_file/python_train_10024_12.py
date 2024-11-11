n=int(input())
m=list(map(int,input().split()))
a=max(m)
b=min(m)
c=m.index(a)
m.reverse()
d=m.index(b)
if c+d<n-1:
    print(c+d)
else:
    print(c+d-1)