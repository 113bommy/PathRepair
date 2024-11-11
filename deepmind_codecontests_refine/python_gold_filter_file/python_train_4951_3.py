
n = int(input())
l = [[0 for i in range(n)] for j in range(n)]
r = 1
# from math import ceil
for i in range(n):
	if i <= int(n/2):
		for j in range(int(n/2)-i,int(n/2)+i+1):
			l[i][j] = r
			r = r + 2
	else:
		for j in range(i-int(n/2),n-(i-int(n/2))):
			l[i][j] = r
			r = r + 2

r = 2
for i in range(n):
	for j in range(n):

		if l[i][j] == 0:
			l[i][j] = r
			r = r + 2

for i in range(n):
	print(*l[i])