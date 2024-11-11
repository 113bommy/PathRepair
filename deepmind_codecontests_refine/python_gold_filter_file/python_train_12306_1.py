from math import factorial as f

for test in range(int(input())):
	k = int(input())
	a = []
	d = 2
	while k:
		a.append(k%d)
		k //= d
		d += 1
	n = len(a)
	c0 = a.count(0)
	a.sort(reverse = True)

	ans = 1
	j = 0
	for i in a:
		if i == 0:
			ans *= n-i - j
		else:
			ans *= n-i+1 - j
		j += 1

	if c0:
		badans = 1
		n = len(a)
		j = 1
		for i in range(len(a)-1):
			if (a[i] == 0):
				badans *= max(0,n-a[i] - j)
			else:
				badans *= max(0,n-a[i]+1 - j)
			j += 1
		ans -= badans*c0

	for i in range(max(a)+1):
		ans //= f(a.count(i))
	print(ans-1)

