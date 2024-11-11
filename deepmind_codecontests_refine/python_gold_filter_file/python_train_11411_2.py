from sys import stdin, stdout
n,q,c=map(int,stdin.readline().split())
cs=[[[0]*101 for _ in range(101)] for _ in range(11)]
for k in range(n):
	x,y,s=map(int,stdin.readline().split())
	cs[s][x][y]+=1	

for i in range(1,101):
	for j in range(1,101):
		for k in range(11):
			cs[k][i][j]+=(cs[k][i-1][j]+cs[k][i][j-1]-cs[k][i-1][j-1])

for _ in range(q):
	t,x1,y1,x2,y2=map(int,stdin.readline().split())
	totalb=0
	for k in range(11):
		totalb+=((k+t)%(c+1))*(cs[k][x2][y2]-cs[k][x2][y1-1]-cs[k][x1-1][y2]+cs[k][x1-1][y1-1])
	print(totalb)