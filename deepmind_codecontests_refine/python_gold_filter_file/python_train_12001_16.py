def testCase():
	n, k = map(int, input().split() )
	a = list( map(int, input().split() ) )
	minValue = 1e7 
	minIndex = -1
	for i in range(n):
		if a[i] < minValue:
			minValue = a[i]
			minIndex = i
	ans = 0
	for i in range(n):
		if i == minIndex:
			continue 
		val = k - a[i]
		ans += val // minValue 
		
	print("{}".format(ans))
	

test = int(input())
while test:
	test -= 1 
	testCase()