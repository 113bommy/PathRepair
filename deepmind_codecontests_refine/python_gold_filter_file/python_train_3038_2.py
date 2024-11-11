n = int(input())

x = 0

m = [[-1 for i in range(n)] for i in range(n)]


for i in range(0,n,4):
	for j in range(0,n,4):
		for p in range(i,i+4):
			for q in range(j,j+4):
				m[p][q]= x
				x+=1


for i in range(n):
	print(*m[i])