n = int(input())
a = [ int(s) for s in input().split()]
b = []
b = list(a)
b.sort()
ids = []
r = sum(b) - 2*b[-1]
i, j = 0, 0
if r in b:
	if r == b[-1] and b[-2] != b[-1]:
		print(0)
	else:
		while i < len(a):
			if a[i] == r:
				ids.append(i+1)
				j+=1
			i+=1
		if (sum(a) - b[-1])//2 == b[-2] and (sum(a) - b[-1])%2 == 0:
			if a.index(b[-1])+1 not in ids:
				ids.append(a.index(b[-1])+1)
				j+=1
		print(j)
		print(" ".join(map(str, ids)))
elif (sum(a) - b[-1])//2 == b[-2] and (sum(a) - b[-1])%2 == 0:
	ids.append(a.index(b[-1]))
	print(1)
	print(ids[0]+1)
else:
	print(0)