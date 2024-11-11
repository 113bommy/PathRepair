(h,n),*t=[[*map(int,t.split())]for t in open(0)]
d=[0]*9**8
for i in range(h):d[i+1]=min(b+d[i-a+1]for a,b in t)
print(d[h])