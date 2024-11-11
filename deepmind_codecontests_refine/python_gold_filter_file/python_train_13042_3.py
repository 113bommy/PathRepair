for _ in range(int(input())):
	n,m=map(int,input().split())
	l=[]
	for i in range(n):
		s=str(input())
		t=[]
		for i in range(len(s)):
			t.append(int(s[i]))
		l.append(t)

	lf=[]
	for i in range(n-2):
		for j in range(m):
			if(j==m-1):
				if(l[i][j]==1):
					lf.append([i,j,i+1,j-1,i+1,j])
					l[i][j]=0
					l[i+1][j-1]=1-l[i+1][j-1]
					l[i+1][j]=1-l[i+1][j]
			else:
				if(l[i][j]==1):
					lf.append([i,j,i+1,j+1,i+1,j])
					l[i][j]=0
					l[i+1][j+1]=1-l[i+1][j+1]
					l[i+1][j]=1-l[i+1][j]

	if(m%2!=0):
		if(l[n-2][m-1]==1):
			lf.append([n-2,m-1,n-2,m-2,n-1,m-2])
			l[n-2][m-1]=0
			l[n-2][m-2]=1-l[n-2][m-2]
			l[n-1][m-2]=1-l[n-1][m-2]

		if(l[n-1][m-1]==1):
			lf.append([n-1,m-1,n-2,m-2,n-1,m-2])
			l[n-1][m-1]=0
			l[n-2][m-2]=1-l[n-2][m-2]
			l[n-1][m-2]=1-l[n-1][m-2]

	i=n-2
	for j in range(0,m-1,2):
		if(l[i][j]==1 and l[i+1][j]==1 and l[i][j+1]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i+1,j,i,j+1])
			lf.append([i,j,i+1,j,i+1,j+1])
			lf.append([i,j,i,j+1,i+1,j+1])
			lf.append([i,j+1,i+1,j,i+1,j+1])
			
		elif(l[i][j]==1 and l[i+1][j]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i+1,j,i+1,j+1])
			
		elif(l[i][j]==1 and l[i][j+1]==1 and l[i+1][j]==1):
			lf.append([i,j,i,j+1,i+1,j])
			
		elif(l[i][j]==1 and l[i][j+1]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i,j+1,i+1,j+1])
			
		elif(l[i][j+1]==1 and l[i+1][j]==1 and l[i+1][j+1]==1):
			lf.append([i,j+1,i+1,j,i+1,j+1])
			
		elif(l[i][j]==1 and l[i+1][j]==1):
			lf.append([i,j+1,i+1,j+1,i+1,j])
			lf.append([i,j,i,j+1,i+1,j+1])
			
		elif(l[i][j]==1 and l[i][j+1]==1):
			lf.append([i,j+1,i+1,j,i+1,j+1])
			lf.append([i,j,i+1,j+1,i+1,j])
			
		elif(l[i][j+1]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i,j+1,i+1,j])
			lf.append([i,j,i+1,j,i+1,j+1])
			
		elif(l[i+1][j]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i+1,j,i,j+1])
			lf.append([i,j,i,j+1,i+1,j+1])
			
		elif(l[i][j]==1 and l[i+1][j+1]==1):
			lf.append([i,j,i+1,j,i,j+1])
			lf.append([i+1,j+1,i+1,j,i,j+1])
			
		elif(l[i][j+1]==1 and l[i+1][j]==1):
			lf.append([i,j,i,j+1,i+1,j+1])
			lf.append([i,j,i+1,j,i+1,j+1])
			
		elif(l[i][j]==1):
			lf.append([i,j,i,j+1,i+1,j+1])
			lf.append([i,j,i+1,j,i+1,j+1])
			lf.append([i,j,i+1,j,i,j+1])
			
		elif(l[i][j+1]==1):
			lf.append([i,j+1,i+1,j,i+1,j+1])
			lf.append([i,j,i+1,j,i,j+1])
			lf.append([i,j,i,j+1,i+1,j+1])
			
		elif(l[i+1][j]==1):
			lf.append([i,j,i,j+1,i+1,j])
			lf.append([i,j,i+1,j,i+1,j+1])
			lf.append([i,j+1,i+1,j,i+1,j+1])
			
		elif(l[i+1][j+1]==1):
			lf.append([i,j,i+1,j,i+1,j+1])
			lf.append([i,j,i,j+1,i+1,j+1])
			lf.append([i+1,j,i,j+1,i+1,j+1])
			
	
	print(len(lf))
	for i in range(0,len(lf)):
		for j in range(6):
			print(lf[i][j]+1,end=" ")
		print()
	