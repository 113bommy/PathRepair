for _ in range(int(input())):
	n = int(input())
	a = sorted(list(map(int,input().split())))
	a.reverse()
	if 2048 in a:
		print('YES')
	else:
		p = 0
		for i in range(n):
			if a[i]<2048: p = i; break
		a = a[p:]
		s = 0
		for i in range(len(a)):
			s += a[i]
			if s==2048: print('YES'); break
		else: print('NO')