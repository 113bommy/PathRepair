from collections import deque 

N,M = map(int, input().split())
root = [[] for _ in range(N)]

for _ in range(M):
	a,b = map(int,input().split())
	root[a - 1].append(b)
	root[b - 1].append(a)

q = deque()
q.append(1)
ans = [0 for _ in range(N)]

while len(q) > 0:
	v = q.popleft()
	for ike in root[v - 1]:
		q.append(ike)
		if(ans[ike - 1] == 0):
			ans[ike - 1] = v

	root[v-1].clear()

print('Yes')
for a in ans[1::]:
	print(a)