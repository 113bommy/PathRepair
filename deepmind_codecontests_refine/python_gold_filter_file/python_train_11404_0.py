# your code goes here
n,t=input().split();
n=int(n)
t=int(t)
lis=[]
for i in range(n):
	l=[0]*(i+1)
	lis.append(l)
lis[0][0]=t
c=0
for i in range(n):
	for j in range(i+1):
		if(lis[i][j]>=1):
			r=lis[i][j]-1
			lis[i][j]=1
			c+=1
			if(i!=n-1):
				lis[i+1][j]+=r/2
				lis[i+1][j+1]+=r/2
print(c)