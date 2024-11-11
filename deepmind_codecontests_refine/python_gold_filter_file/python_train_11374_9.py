t=int(input())
for i in range(0,t):
	L=[]
	nm=input().split()
	n=int(nm[0])
	m=int(nm[1])
	for i in range(0,n):
		M=list(map(int,input().split()))
		L.append(M)
	N=[[0 for i in range(n+m-1)] for j in range(2)]
	sum=0
	for i in range(0,n):
		for j in range(0,m):
			#if(L[i][j]!=L[n-1-i][m-1-j]):
			if(L[i][j]==0):
				N[0][i+j]+=1
			else:
				N[1][i+j]+=1

	for i in range(0,(n+m-1)//2):
		sum+=min(N[0][i]+N[0][n+m-2-i],N[1][i]+N[1][n+m-2-i])
	print(sum)