
T=int(input());
for t in range(T):
	
	[n,m,x,y]=list(map(int,input().split()));
	c1,c2=0,0;
	for i in range(n):
		a=list(input());
		j=0;
		while(j<m):
			if(a[j]=="." and j+1<m and a[j+1]=="."):c2+=1;j+=1;
			elif(a[j]=="."):c1+=1;
			j+=1;
	if(2*x<y):print((c1+2*c2)*x);
	else:print(c1*x+c2*y);

	



























