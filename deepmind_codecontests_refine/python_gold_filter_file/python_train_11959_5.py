while True:
	n=int(input())
	if n==0:
		break
	A=[]
	for i in range(n):
		x=int(input())
		A.append(x)

	B=[int()]*n
	B[0]=A[0]
	for i in range(1,n):
		if A[i]>=A[i]+B[i-1]:
			B[i]=A[i]
		else:
			B[i]=A[i]+B[i-1]
	print(max(B))