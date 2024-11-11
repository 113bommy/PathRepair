a = [int(i) for i in input().split()]
p = [(a[0]*a[1])+(2*a[3]), (a[0]*a[2])+(2*a[4])]
if p[0] == p[1]:
	print('Friendship')
elif p[0] < p[1]:
	print('First')
else:
	print('Second')