from math import ceil
n = int(input())
X = list(map(int,input().split()))
for x in X:
	#print((x-20)/14)
	#print((x-15)/14)
	res = "NO"
	l = ceil((x - 20) / 14)
	for k in range(l+100, l-101, -1):
		if k >= 0 and 15+14*k<=x<=20+14*k:
			res = "YES"
			break
	print(res)
	'''
	l = max(0, l)
	r = (x - 15) // 14
	print(l, r)
	res = "NO"
	for k in range(l, r+1):
		if 15+14*k<=x<=20+14*k:
			res = "YES"
			break
	print(res)
	'''
	