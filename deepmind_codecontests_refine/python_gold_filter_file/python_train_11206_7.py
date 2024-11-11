s = set()
a, b = map(int, input().split())
for i in range(1, b + 1):
	if a % i in s:
		exit(print('No'))
	s.add(a % i)
print('Yes')