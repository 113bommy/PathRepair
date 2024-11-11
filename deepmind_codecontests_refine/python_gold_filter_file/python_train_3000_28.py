n,m,*a=map(int,open(0).read().split())
d=[0]*n*9
for i in range(n):
 for j in a:c=i+(0,2,5,5,4,5,6,3,7,6)[j];d[c]=max(d[c],(d[i]*10+j)*(i<1or d[i]>0))
print(d[n])