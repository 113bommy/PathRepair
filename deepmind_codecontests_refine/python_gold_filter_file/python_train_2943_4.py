n,m = map(int,input().split())
mat = []
for i in range(n):
	mat.append(list(input()))
curr = [[1 for i in range(m)] for j in range(n)]
for i in range(2,n):
	for j in range(1,m-1):
		if mat[i][j]==mat[i-1][j-1]==mat[i-2][j]==mat[i-1][j+1]==mat[i-1][j]:
			curr[i][j] = min(curr[i-1][j-1],curr[i-2][j],curr[i-1][j+1])+1
		
ans = 0
for i in curr:
	for j in i:
		ans += j
# for i in curr:
	# print (*i)
print (ans)
