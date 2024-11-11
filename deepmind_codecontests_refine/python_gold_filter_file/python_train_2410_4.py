import io, os
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline
kk=lambda:map(int,input().split())
k2=lambda:map(lambda x:int(x)-1, input().split())
ll=lambda:list(kk())
n = int(input())
if n < 3:
	print(-1)
	exit()
parents = [-1]*n
children = [[] for _ in range(n)]
ok = [-1]*n
pos = [True]*n
for node in range(n):
	p,c = k2()
	parents[node] = p
	children[p].append(node)
	ok[node] = c+1
	if c==-1: 
		pos[node] = pos[p if p != -2 else node] = False
tbp = []
for node in range(n):
	if pos[node]: tbp.append(node+1)
print(-1 if len(tbp) == 0 else " ".join(map(str, tbp)))