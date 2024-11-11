t=int(input())
while t>0:
	t-=1
	n,m=map(int,input().split())
	s=[]
	for i in range(n):
		a=list(map(int,input().split()))
		s.append(a)
		z=True
	for i in range(n):
		for j in range(m):
			if i==0 or i==n-1:
				if j==0 or j==m-1:
					if s[i][j]<=2:
						s[i][j]=2
					else:
						z=False
						break
				else:
					if s[i][j]<=3:
						s[i][j]=3
					else:
						#print['NO']
						z=False
						break					
			else:
				if j==0 or j==m-1:
					if s[i][j]<=3:
						s[i][j]=3
					else:
						#print['NO']
						z=False
						break
				else:
					if s[i][j]<=4:
						s[i][j]=4
					else:
						#print['NO']
						z=False
						break
	if z==True:
		print('YES')
		for i in range(n):
			for j in s[i]:
				print(j,end=' ')
			print()
	else:
		print('NO')



