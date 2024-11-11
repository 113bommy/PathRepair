t = int(input())

for ii in range(t):
	n, x = map(int, input().split())

	l = list(map(int, input().split()))

	l.sort(reverse = True)

	cnt = 0

	tempMin = l[0]
	tempCnt = 0
	for i in l:
		# print(tempMin, tempCnt)
		if tempMin*tempCnt >= x:
			cnt+=1
			tempCnt = 0

		tempMin = i
		tempCnt += 1

	if tempMin*tempCnt >= x:
			cnt+=1
			tempCnt = 0

	print(cnt)	