trials = int(input())
answer = list()
for k in range(trials):
	line = input()
	ls = line.split()
	count = len(ls[0])
	a = ls[0]
	n = int(ls[1])
	for j in range(n-1):
		dig = list(map(list, a))
		m = int(dig[0][0])
		o = int(dig[0][0])
		for i in range(len(dig)):
			m = max(m,int(dig[i][0]))
			o = min(o,int(dig[i][0]))
		a = int (int(a) + (m*o))
		dig = list()
		a = str(a)
		if not a.find('0') == -1:
			break
	answer.append(a)
for i in answer:
	print(int(i))


