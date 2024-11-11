tests = int(input())
while tests:
	tests -= 1
	l = sorted(list(map(int, input().split())))
	diff = abs(l[2] - l[1])
	if diff > l[0] + 1:
		print('No')
	else:
		print('Yes')
