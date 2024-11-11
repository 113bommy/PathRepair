import math

for _ in range(int(input())):
	n = int(input())
	lengths = [1]
	total_area = 1
	lengths.append(2*lengths[-1]+1)
	add = lengths[-1]*(lengths[-1]+1)//2
	while total_area + add <= n:
		total_area += add
		lengths.append(2*lengths[-1]+1)
		add = lengths[-1]*(lengths[-1]+1)//2
	print(len(lengths)-1)

	