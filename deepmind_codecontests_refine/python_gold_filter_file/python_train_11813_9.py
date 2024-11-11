[n,m]=[int(x) for x in input().split()]

matrix=[]

for _ in range(n):
	l=[int(x) for x in input().split()]
	matrix.append(l)

def operation_or(l):

	row_op=[]
	col_op=[]
	output=[]
	for i in range(n):
		temp=1
		for j in range(m-1):
			temp=temp and matrix[i][j] and matrix[i][j+1]
		row_op.append(temp)

	for j in range(m):
		temp=1
		for i in range(n-1):
			temp=temp and matrix[i][j] and matrix[i+1][j]
		col_op.append(temp)		
	for i in range(n):
		temp=[]
		for j in range(m):
			temp.append(row_op[i] and col_op[j])
		output.append(temp)
	return output	

def operation_and(l):

	row_op=[]
	col_op=[]
	output=[]
	for i in range(n):
		temp=0
		for j in range(m-1):
			temp=temp or l[i][j] or l[i][j+1]
			# print(temp)
		row_op.append(temp)
	# print(row_op)	
	for j in range(m):
		temp=0
		for i in range(n-1):
			temp=temp or l[i][j] or l[i+1][j]
		col_op.append(temp)		
	# print(col_op)
	for i in range(n):
		temp=[]
		for j in range(m):
			temp.append(row_op[i] or col_op[j])
		output.append(temp)
	return output	
if n!=1 or m!=1:

	output=operation_or(matrix)
	# print(output)
	op_cmp=operation_and(output)
	# print(op_cmp)
	flag=False

	for i,j in zip(op_cmp,matrix):
		for q,k in zip(i,j):
			if q!=k:
				flag=True
				break
	if flag==True: print('NO')			
	if flag!=True:
		print('YES')
		for i in output:
			for j in i:
				print(j,end=" ")
			print()	
else:
	print('YES')
	print(matrix[0][0])