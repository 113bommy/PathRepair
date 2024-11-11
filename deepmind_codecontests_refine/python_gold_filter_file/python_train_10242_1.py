def lightChanger(i,j):
	output[i][j]=output[i][j]^1
	direction=[[0,1],[1,0],[0,-1],[-1,0]]
	for xDir,yDir in direction:
		x=xDir+i
		y=yDir+j
		if 0<=x<3 and 0<=y<3:
			output[x][y]=output[x][y]^1

matrix=[]
output=[[1 for i in range(3)] for j in range(3)]
for _ in range(3):
    matrix.append(list(map(int,input().split())))


for i in range(3):
	for j in range(3):
		if matrix[i][j]%2==1:
			lightChanger(i,j)

for x in output:
	for i in x:
		print(i,end="")
	print()
