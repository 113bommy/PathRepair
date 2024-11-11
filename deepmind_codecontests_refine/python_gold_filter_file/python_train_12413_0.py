for _ in range(0, int(input())):
	n = int(input())
	l=list(map(int, input().strip().split()))

	h = [0 for a in range(0, n+1)]
	dis=0
	for i in l:
		if h[i]==0:
			dis+=1
		h[ i]+=1
	maximum = max(h)

	if maximum==1:
		if h.count(1)>1:
			print(1)
		else:
			print(0)
		continue

	# print(h)

	if maximum<=dis-1:
		print(maximum)
	else:
		# dis+=1
		while True:
			maximum-=1

			if dis>=maximum:
				print(maximum)
				break