t = int(input())
for i in range(t):
	n = int(input())
	gp = input()
	m = int(input())
	gq = input()
	p = [int(j) for j in gp.split(' ')]
	q = [int(u) for u in gq.split(' ')]
	evenp = 0
	evenq = 0
	for r in p:
		if r % 2 == 0:
			evenp = evenp + 1
	for l in q:
		if l % 2 == 0:
			evenq = evenq + 1
	print(evenq * evenp + (n-evenp)*(m-evenq))
