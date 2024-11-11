import sys
N, M, X=map(int, sys.stdin.readline().rstrip().split())
A = [list(map(int, sys.stdin.readline().rstrip().split())) for i in range(N)]
cost=[]
for i in range(1<<N):	#Bit All Search
	l=[0]*(M+1)
	for j in range(N):
		if((i>>j)&1)==1:
			l=[l[k]+A[j][k] for k in range(M+1)]
	for k in range(M):
		if l[k+1]<X:
			break
	else:
		cost.append(l[0])
cost.sort()
print(-1 if cost==[] else cost[0])