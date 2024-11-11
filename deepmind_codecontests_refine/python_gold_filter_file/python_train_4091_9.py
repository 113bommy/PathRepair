t = int(input())
for t1 in range(0, t):
	n, w = map(int, input().split())
	if w % 2 == 0:
		w2 = int(w / 2)
	else:
		w2 = int(w / 2) + 1
	#mas = [0] * n
	mas1 = list(map(int, input().split()))
	mas = [(1, 1)] * n
	for i in range(0, n):
		mas[i] = (mas1[i], i + 1)
	mas.sort()
	#for i in mas:
	#	print(i[0], i[1])
	su = 0
	fl = 0
	for i in range(0, n):
		su += mas[i][0]
		if (su >= w2 and su <= w):
			print(i + 1)
			for j in range(0, i + 1):
				print(mas[j][1], end = ' ')
			print()
			fl = 1
			break
		elif su >= w and mas[i][0] <= w:
			print(1)
			print(mas[i][1])
			fl = 1
			break
	if (fl == 0):
		print(-1)