n,x,y=input().split();
n=int(n);
x=int(x);
y=int(y);

inp=input().split();

a=[];

for i in range(n):
	a.append(int(inp[i]));

a.sort();

if(x>y):
	print(n);
#1,2,2,3,4
else:
	for j in range(10000):
		for i in range(n-1):
			a[i]=max(0,a[i]-x);
			if(a[i]>0):
				a[i]+=y;
			else:
				a[i+1]+=y;
		a[n-1]=max(0,a[n-1]-x);
		if(a[n-1]>0):
			a[n-1]+=y;
		#a.sort();

	ctr=0;

	for i in a:
		if(i==0):
			ctr+=1;
	print(ctr)