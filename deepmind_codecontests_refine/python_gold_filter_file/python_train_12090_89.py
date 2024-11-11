test = int(input())
while(test):
	test = test - 1
	s = list(map(int, input().split(" ")))
	l = s[0]
	r = s[1]
	k = 1
	for x in range(l,r):
		t = x*2
		if t<=r:
			print(x, end=" ")
			print(t)
			break