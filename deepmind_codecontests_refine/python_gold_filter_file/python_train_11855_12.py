n,*l=map(int,open(0).read().split());a=[0,1]+[0]*n;b=[1]*-~n
for i,j in zip(l[1::2],l[2::2]):a[j]|=a[i];b[i]-=1;b[j]+=1;a[i]&=(b[i]>0)
print(sum(a))