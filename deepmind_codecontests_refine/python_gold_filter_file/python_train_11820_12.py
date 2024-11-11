def p1():
	n,m = [int(i) for i in input().split()]
	l = [int(i) for i in input().split()]
	k = []
	i = 1
	f = 1
	while f:
		while i in l and i <= m:
			i = i+1
		if i <= m :
			k.append(i)
			m = m-i
		else:
			f = 0
		i = i+1
	print(len(k))
	for i in k:
		print(i,end = ' ')
def p2():
	n = int(input())
	l = list(set([int(i) for i in input().split()]))
	l.sort()
	ans = 'NO'
	for i in range(len(l)-3+1):
		if l[i] == l[i+1]-1 and l[i+1] == l[i+2]-1:
			ans = 'YES'
			break
	print(ans)
p2()
