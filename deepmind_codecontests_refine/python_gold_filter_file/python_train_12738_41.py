n = int(input())
l = []
if n%2 == 1:
	print('-1')
else:
	for i in range(1,n+1,1):
		l.append(i)

	for i in range(0,n-1,2):
		l[i],l[i+1] = l[i+1],l[i]

	print(" ".join(map(str, l)))









