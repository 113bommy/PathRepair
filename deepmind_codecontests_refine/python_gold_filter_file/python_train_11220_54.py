n,*a=map(int,open(0).read().split());z=1
for i in a:
 if i>1e18//z:z=-1;break
 z*=i
print(0 if 0in a else z)