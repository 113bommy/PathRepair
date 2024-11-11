n = int(input())
arr = []
c,c1 = 0,0
for i in range (n):
	l = list(map(int,input().split(' ')))
	arr.append(l)
for i in range (n):
	for j in range (3):
		if (arr[i][j]==1):
			c+=1
	if (c>=2):
		c1+=1
	c = 0
print (c1)