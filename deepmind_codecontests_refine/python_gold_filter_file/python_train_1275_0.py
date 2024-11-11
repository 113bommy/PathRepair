from sys import stdin,stdout
import sys
sys.setrecursionlimit(100000)
# stdin=open("input.txt","r")
# stdout=open("output.txt","w")
	

def block(mtr,taken_care_of,x,y,n,m):
	# print(y,x,taken_care_of[y][x])
	taken_care_of[y][x]=True
	for row_offset,col_offset in [(0,1),(0,-1),(1,0),(-1,0)]:
		if y+row_offset>=0 and y+row_offset<n and x+col_offset<m and x+col_offset>=0:
			# print(y+row_offset,x+col_offset,row_offset,col_offset)
			if mtr[y+row_offset][x+col_offset]=='.':
				mtr[y+row_offset][x+col_offset]='#'
			if mtr[y+row_offset][x+col_offset]=='B' and not taken_care_of[y+row_offset][x+col_offset]:
				block(mtr,taken_care_of,x+col_offset,y+row_offset,n,m)



	
t = int(stdin.readline().strip())
for _ in range(t):
	n,m = stdin.readline().strip().split(' ')
	n,m = int(n),int(m)

	mtr=[]
	for i in range(n):
		mtr.append(list(stdin.readline().strip()))

	taken_care_of = [[False for i in range(m)]for j in range(n)]

	for i in range(n):
		for j in range(m):
			if not taken_care_of[i][j] and mtr[i][j]=='B':
				block(mtr,taken_care_of,j,i,n,m)

	can_reach = [[False for i in range(m)]for j in range(n)]
	
	queue=[]
	if mtr[n-1][m-1]!="#":
		queue.append((n-1,m-1))
		can_reach[n-1][m-1]=True
	else:
		can_reach[n-1][m-1]=False
	while len(queue)>0:
		y,x=queue.pop(-1)
		# print(x,y)
		for row_offset,col_offset in [(0,1),(0,-1),(1,0),(-1,0)]:
			# print(x+col_offset,y+row_offset)
			if y+row_offset>=0 and y+row_offset<n and x+col_offset<m and x+col_offset>=0 and mtr[y+row_offset][x+col_offset]!='#' and not can_reach[y+row_offset][x+col_offset]:
				queue.append((y+row_offset,x+col_offset))
				can_reach[y+row_offset][x+col_offset]=True

	ans=True

	# for i in mtr:
	# 	print(i)
	# print()
	# for i in can_reach:
	# 	print(i)
	# print("\n")

	for i in range(n):
		for j in range(m):
			if (mtr[i][j]=='B' and can_reach[i][j]==True) or (mtr[i][j]=='G' and can_reach[i][j]==False):
				ans=False



	if ans:
		stdout.write("Yes\n")
	else:
		stdout.write("No\n")








