t = int(input())
#t = 1
for i in range(t):
	l = list(map(int, input().split()))
	#l = [5, 1]
	m = [0]
	for i in range(l[0] - 1):
		temp = i + 1 + m[0]
		if temp > l[1]:
			x2 = l[0]-(l[1] - m[0])
			break
		elif temp == l[1]:
			x2 = l[0]-(l[1] - m[0])
			break
		m.insert(0, temp)
	#print(m)
	#print(temp)
	x1 = l[0] - 2 - i
	#print(x1, x2)
	s = "a"*l[0]
	s = s[:x1] + "b" + s[x1 + 1: x2:] + "b" + s[x2 + 1:]
	print(s)