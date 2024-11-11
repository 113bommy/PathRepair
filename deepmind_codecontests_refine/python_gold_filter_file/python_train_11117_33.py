n,m = map(int,input().split())
L = [0]*n
AC = 0
WA = 0
tmp = [0]*n
for i in range(m):
	x,y = input().split()
	x = int(x)
	if L[x-1] == 0:
		if y == "WA":
			tmp[x-1] += 1
		else:
			AC += 1
			WA += tmp[x-1]
			L[x-1]=1
print(AC,WA)
