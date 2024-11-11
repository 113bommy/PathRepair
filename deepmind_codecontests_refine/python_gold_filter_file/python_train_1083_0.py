def solution() : # 最大的距离来自于角落附近的点
	n,m,k,s = map(int, input().split())
	dis = lambda a,b : abs(a[0] - b[0]) + abs(a[1] - b[1])
	corner = [(0,0), (0,m-1), (n-1,0), (n-1,m-1)]
	vertex = [[(n,m), (n,-1), (-1,m), (-1,-1)] for _ in range(k+1)]
	for i in range(n) :
		for j,note in enumerate(map(int, input().split())) :
			vertex[note] = [
				(i,j) if dis((i,j), c) < dis(v, c) else v
				for v,c in zip(vertex[note], corner)]
	maxdis = [[-1] * (k+1) for _ in range(k+1)]
	pairs = [(0,3),(3,0),(1,2),(2,1)]
	for i in range(1, k+1) :
		for j in range(i, k+1) :
			vi,vj = vertex[i],vertex[j]
			maxdis[i][j] = max(dis(vi[a], vj[b]) for a,b in pairs)
			maxdis[j][i] = maxdis[i][j]
	s = list(map(int, input().split()))
	print(max(maxdis[s[i]][s[i+1]] for i in range(len(s) - 1)))
solution()