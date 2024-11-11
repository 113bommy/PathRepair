# from debug import debug

t = int(input())
for ii in range(t):
	n, l, r = map(int, input().split())
	s = []

	count = 1
	ans = count*(2*(n-1) + 1- count)
	while ((n-count)>0 and ans<l):
		count+=1
		ans = count*(2*(n-1) + 1- count)
	count-=1
	remain = l-count*(2*(n-1) + 1- count)-1

	val = 0
	b = 0
	for i in range(count, n):
		for j in range(i+1, n):
			s.append(i+1)
			s.append(j+1)
			val+=2
			if val>r-l+remain+1:
				b = 1
				break
		if b:
			break

	s.append(1)
	q = s[remain:r-l+1+remain]
	for i in range(len(q)-1):
		print(q[i], end=" ")
	print(q[-1])

	
