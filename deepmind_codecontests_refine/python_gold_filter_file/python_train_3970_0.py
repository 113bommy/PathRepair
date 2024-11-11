n=int(input())
l=[input() for i in range(2*n-2)]
m=[i+j for i in l for j in l if len(i+j)==n]
for j in set(m):
	p = [j[:i] for i in range(1,n)]
	s = [j[i:] for i in range(1,n)]
	if set(p+s)==set(l):
		for i in l:
			if i in p: print('P',end=''); p.remove(i)
			else: print('S',end=''); s.remove(i)
		exit()