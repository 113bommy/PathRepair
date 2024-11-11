
n1,n2,n3 = map(int,input().split(" "))

list1 = [list(map(int,input().split(" "))) for _ in range(n1)]
list2 = [list(map(int,input().split(" "))) for _ in range(n2)]

mat = [[0 for _ in range(n3)] for _ in range(n1)]
for i in range(n1):
	for j in range(n2):
		for k in range(n3):
			mat[i][k] += list1[i][j] * list2[j][k]

for m in mat:
	print(*m)

