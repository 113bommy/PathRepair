import sys
input = sys.stdin.readline
'''
allinputs = iter(input().splitlines())
input = lambda : next(allinputs)
#'''

N, M = map(int,input().split())
q = []
c = [0] * N
A = [[] for i in range(N)]

for i in range(M):
	x, y, z = map(int,input().split())
	x = x - 1
	y = y - 1
	A[x].append(y)
	A[y].append(x)

cost = 0
for i in range(N):
	if c[i] == 0:
		cost += 1
		q.append(i)
		while len(q):
			j = q.pop()
			c[j] = 1
			for k in A[j]:
				if c[k] == 0:
					q.append(k)

print(cost)
