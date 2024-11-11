n,m,x=map(int,input().split())
c=[]
a=[]
for i in range(n):
	C,*A=map(int,input().split())
	c.append(C)
	a.append(A)

ans=[]
for i in range(2**n):
	A=[0]*m
	C=0
	lst=list(map(int,format(i,'b').zfill(n)))
	for j in range(n):
		if lst[j]==1:
			C+=c[j]
			for k in range(m):
				A[k]+=a[j][k]
	if all(elem>=x for elem in A):
		ans.append(C)
if len(ans):
	print(min(ans))
else:
	print(-1)