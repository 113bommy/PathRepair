n,q = map(int,input().split())
queue = []
for i in range(n):
	name,time = input().split()
	queue.append([name, int(time)])

t = 0
i = 0
while queue:
	i %= len(queue)
	p = queue[i]
	t += min(q, p[1])
	if p[1] > q:
		p[1] -= q
		i += 1
	else:
		print(p[0], t)
		queue.pop(i)
