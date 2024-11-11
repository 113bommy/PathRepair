n, m = map(int, input().split())
s = input()
t = input()

i = 0
mi = []
ma = 1001
while i < m - n + 1:
	ki = []
	j = 0
	while j < n:
		p = i + j
		if s[j] != t[p]:
			ki.append(j + 1)
		j += 1
	if len(ki) < ma:
		ma = len(ki)
		mi = ki
	i += 1
	
print(len(mi))
print(' '.join([str(i) for i in mi]))