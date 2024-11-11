n=int(input());
deg=list(map(int,input().split()));

sumd=0;
deg_1=[];
deg_2=[];
for i in range(n):
	sumd+=deg[i];
	if (deg[i]>1):
		deg_2.append(i);
	else:
		deg_1.append(i);
if (sumd<2*n-2):
	print("NO");
else:
	l1=len(deg_1);
	l2=len(deg_2);
	while (l1<2):
		deg_1.append(deg_2[l2-1]);
		l1+=1;
		l2-=1;
	print("YES %d"%(n+1-l1));
	print(n-1);
	for i in range(l2-1):
		print("%d %d"%(deg_2[i]+1,deg_2[i+1]+1));
		deg[deg_2[i]]-=1;
		deg[deg_2[i+1]]-=1;
	print("%d %d"%(deg_2[l2-1]+1,deg_1[0]+1));
	deg[deg_2[l2-1]]-=1;
	j=0;
	for i in range(1,l1):
		while (deg[deg_2[j]]==0):
			j+=1;
		print("%d %d"%(deg_1[i]+1,deg_2[j]+1));
		deg[deg_2[j]]-=1;








