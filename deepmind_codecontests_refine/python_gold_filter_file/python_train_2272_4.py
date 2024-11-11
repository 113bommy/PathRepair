import itertools
N,C = map(int,input().split(' '))
D = [list(map(int,input().split(' '))) for i in [0]*C]
c = [list(map(int,input().split(' '))) for i in [0]*N]


l = [[],[],[]]
n = 0
for i in range(N):
	for j in range(i+1):
		l[n].append(c[i-j][j])
	n = (n+1) % 3
for i in range(N-1):
	for j in range(N-i-1):
		l[n].append(c[i+j+1][N-j-1])
	n = (n+1) % 3

d1,d2,d3 = [[sum([D[j-1][i] for j in l[n]]) for i in range(C)] for n in range(3)]

ans = 1000*500*500
colors = list(range(C))
for c1,c2,c3 in itertools.permutations(colors,3):
	ans = min(ans,d1[c1] + d2[c2] + d3[c3])
print(ans)



