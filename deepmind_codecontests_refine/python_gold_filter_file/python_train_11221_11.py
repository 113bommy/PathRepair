(h,n),*t=[list(map(int,o.split()))for o in open(0)]
d=[0]*(h+10100)
for i in range(1,h+1):d[i]=min(d[i-a]+b for a,b in t)
print(d[h])