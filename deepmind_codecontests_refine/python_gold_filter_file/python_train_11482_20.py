def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

t = int(input())
for t1 in range(t):
	n    = int(input())
	a    = [int(n1) for n1 in input().split()]
	n1   = a[0]
	last = -1
	same = []
	res = all(ele == a[0] for ele in a) 
	if res:
		print('NO')
	else:
		print('YES')
		for i in range(1,len(a)):
			if n1==a[i]:
				same.append(i)
			else:
				print(1,i+1)
				last = i
		for j in range(len(same)):
			print(last+1,same[j]+1)

'''
for i in range(n):
for j in range(n):
for k1 in range(len(a)):
for k2 in range(len(a)):
for k3 in range(len(a)):

'''