n=int(input())
A=list(map(int,input().split()))

for i in range(1,n):
	print(" ".join(map(str,A)))
	j=i
	while A[j]<A[j-1] and j>0:
		(A[j],A[j-1])=(A[j-1],A[j])
		j=j-1
else:
	print(" ".join(map(str,A)))