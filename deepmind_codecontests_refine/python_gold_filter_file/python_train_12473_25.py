n,*h=map(int,open(0).read().split());d=[0]*n;d[1]=abs(h[1]-h[0])
for i in range(2,n):
  d[i]=min(d[i-1]+abs(h[i]-h[i-1]),d[i-2]+abs(h[i]-h[i-2]))
print(d[-1])