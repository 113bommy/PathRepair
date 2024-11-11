# your code goes here
arr=[[1,1,1],[1,1,1],[1,1,1]]
toggle=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(0,3):
	var=[int(x)%2 for x in input().split()]
	toggle[i]=var

for i in range(0,3):
	for j in range(0,3):
		if(toggle[i][j]==1):
			arr[i][j]=(arr[i][j]+1)%2
		if(i>=1 and toggle[i][j]==1):
			arr[i-1][j]=(arr[i-1][j]+1)%2
		if(j>=1 and toggle[i][j]==1):
			arr[i][j-1]=(arr[i][j-1]+1)%2
		if(i<=1 and toggle[i][j]==1):
			arr[i+1][j]=(arr[i+1][j]+1)%2
		if(j<=1 and toggle[i][j]==1):
			arr[i][j+1]=(arr[i][j+1]+1)%2
			
for i in range(0,3):
	for j in range(0,3):
		print(arr[i][j],end='')
	print()

			