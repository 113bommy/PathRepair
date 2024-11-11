for ti in range(int(input())):
	n, c0,c1, h = map(int, input().split())
	s = input()
	n1 = s.count('1')
	n0 = s.count('0')
	print(n1*min(c1,h+c0)+ n0*min(c0,h+c1))