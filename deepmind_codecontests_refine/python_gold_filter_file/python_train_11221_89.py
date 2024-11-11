h,n,*t=map(int,open(0).read().split())
d=[0]+[9e9]*h
for a,b in zip(*[iter(t)]*2):
 for j in range(h+1):d[j]=min(d[j],d[max(0,j-a)]+b)
print(d[h])