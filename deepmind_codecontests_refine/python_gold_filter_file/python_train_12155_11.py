
n,m=[int(x) for x in input().strip().split(' ')]
a=[]
for _ in range(n):
	s=input().strip()
	b=[]
	for i in range(m):
		if s[i]=='*':
			b.append(-100)
		elif s[i]=='.':
			b.append(0)
		else:
			b.append(int(s[i]))
	a.append(b)
#print(a)
for i in range(n):
	for j in range(m):
		if a[i][j]<=-100:
			if i<n-1 and j<m-1:
				a[i+1][j+1]-=1
			if i<n-1 and j>0:
				a[i+1][j-1]-=1
			if i>0 and j<m-1:
				a[i-1][j+1]-=1
			if i>0 and j>0:
				a[i-1][j-1]-=1
			if j<m-1:
				a[i][j+1]-=1
			if i<n-1:
				a[i+1][j]-=1
			if i>0:
				a[i-1][j]-=1
			if j>0:
				a[i][j-1]-=1
ans=True
#print(a)
for i in range(n):
	if ans==False:
		break
	for j in range(m):
		if a[i][j]!=0 and a[i][j]>-100:
			ans=False
			break
if ans:
	print("YES")
else:
	print("NO")