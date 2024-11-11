from collections import defaultdict
from collections import deque
N = int(input())
# A_i,j = A[i-1][j-1]
A = [list(map(int,input().split(' '))) for i in [0]*N]

dic = defaultdict(int)
ns = [0] * N

ls = range(1,N+1)
ans = 0
while(True):
	new_ls = set([])
	for i in ls:
		if ns[i-1] >= N-1:
			continue
		j = A[i-1][ns[i-1]]
		dic[(i*j,i+j)] += 1
		if dic[(i*j,i+j)] == 2:
			new_ls.add(i)
			new_ls.add(j)
	if not new_ls:
		break
	for ind in new_ls:
		ns[ind-1] += 1
	ls = new_ls
	ans += 1

for i in range(N):
	if ns[i] != N-1:
		print(-1)
		exit()
print(ans)






