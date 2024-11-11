n,k = map(int, input().split())

a = []
b = []
comman = []
a_ = []
b_ = []
for _ in range(n):
	t,ai,bi = map(int, input().split())
	a_.append(ai)
	b_.append(bi)
	if ai == 1 and bi == 1:
		comman.append(t)
	elif ai == 1:
		a.append(t)
	elif bi == 1:	
		b.append(t)
	

a.sort()
b.sort()
#comman.sort()

if a_.count(1) < k or b_.count(1) < k:
	print(-1)

else:
	s = 0
	m = min(len(a),len(b))
	for i in range(m):
		comman.append(a[i]+b[i])

	comman.sort()
	print(sum(comman[:k]))






