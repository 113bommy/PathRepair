def main():
	n, m = map(int, input().split())
	g = [[0] * n for i in range(n)]
	for i in range(m):
		x, y = map(int, input().split())
		g[x-1][y-1] = 1
		g[y-1][x-1] = 1
	a, c = -1, -1 
	for i in range(n):
		for j in range(i+1,n):
			if(g[i][j] == 0):
				a, c = i, j
	if((a, c) == (-1, -1)):
		print("Yes")
		print("a"*n)
		return
	ans = ["x"] * n
	ans[a] = "a"
	ans[c] = "c"
	for i in range(n):
		if(i!=a and i !=c):
			if(g[i][a]+g[i][c] == 2):
				ans[i] = "b"
			elif (g[i][a] == 1):
				ans[i] = "a"
			else:
				ans[i] = "c"
	for i in range(n):
		for j in range(n):
			if(i==j):
				continue
			if(g[i][j] == 0 and (ans[i] + ans[j] != "ac" and ans[i] + ans[j] != "ca")):
				print("No")
				return
			if(g[i][j] == 1 and (ans[i] + ans[j] == "ac" or ans[i] + ans[j] == "ca")):
				print("No")
				return
	print("Yes")
	print("".join(ans))
main()