n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
razl = []
for i in range(n):
	if a[i]!=b[i]:
		razl.append(i)
if len(razl)==1:
	for i in range(1,n+1):
		if i!=a[razl[0]] and i!=b[razl[0]] and (i not in a):
			a[razl[0]]=i 
			break
else:
	if (b[razl[0]] not in a):
		tmp = a[razl[0]]*1
		a[razl[0]] = b[razl[0]]
		if a.count(a[razl[1]])!=1:
			a[razl[0]] = tmp
			a[razl[1]] = b[razl[1]]
	else:
		a[razl[1]] = b[razl[1]]
for i in a:
	print(i, end=' ')