input();a=sorted(map(int,input().split()));z=1
for i in a:
 z*=i
 if z>1e18:z=-1;break
print(z)