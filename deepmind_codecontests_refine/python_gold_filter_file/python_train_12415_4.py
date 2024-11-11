def ok(a):
	for i in range(1, len(a)):
		if a[i]<a[i-1]:
			return False
	return True

def getMex(a):
	vis = [0]*(n+1)
	for x in a:
		vis[x] = 1
	Mex = 0
	while(vis[Mex]):
		Mex += 1
	return Mex

for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	op = []
	while(ok(a)==False):
		cur = getMex(a)
		idx = cur
		if idx==n:
			for i in range(n):
				if a[i]!=i:
					idx = i
					break
		a[idx] = cur
		op.append(idx+1)
	print(len(op))
	print(" ".join(str(i) for i in op))
