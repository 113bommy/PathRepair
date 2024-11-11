#In the name of GOD!
t = int(input())
for i in range(t):
	k = int(input())
	a = list(map(int, input().split()))
	
	sm = sum(a)
	ans = 0
	if k % sm == 0: 
		ans = (k // sm - 1) * 7
		k = sm
	else:
		ans = k // sm * 7
		k %= sm
	
	ad = 7	
	for i in range(7):
		day = 0
		cnt = k
		for j in range(i, i + 7):
			j %= 7
			day += 1
			cnt -= a[j]
			if cnt == 0:
				ad = min(ad, day)
				break
	
	print(ans + ad)
