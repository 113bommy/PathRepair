
from collections import deque




for _ in range(int(input())):
	
	n, s = [i for i in input().split()]
	qu = deque([i for i in s])
	mn = list(range(1, int(n)+1))
	mx = list(range(1, int(n)+1))[::-1]

	arr = []
	cnt = 0
	sym = None
	while qu:
		ele = qu.popleft()
		if sym == ele[0]:
			arr[-1][1]+=1
		else:
			arr.append([ele[0], 1])
			sym = ele[0]

	ind = 0
	for i in arr:
		if i[0] == '<':
			mx[ind:ind+i[1]+1] = mx[ind:ind+i[1]+1][::-1]
		else:
			mn[ind:ind+i[1]+1] = mn[ind:ind+i[1]+1][::-1]
		ind+=i[1]
	print(*mx)
	print(*mn)