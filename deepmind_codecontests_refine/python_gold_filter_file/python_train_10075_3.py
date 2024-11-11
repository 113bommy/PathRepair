n,s,*a=map(int,open(0).read().split());d=[0]*-~s;m=998244353;v=pow(2,m-2,m);d[0]=pow(2,n,m)
for i in a:
  for j in range(s,i-1,-1):d[j]+=(d[j-i]*v)%m
print(d[s]%m)