##
#	Author:		antikostya
#	Created:	2021-10-17 14:01:39
#	Modified:	2021-10-17 15:02:24
##

for _t in range(int(input())):
	n, m = map(int, input().split())
	free = set(range(1, m + 2))
	for i in range(m):
		a, b, c = map(int, input().split())
		free.discard(b)
	# print(free)
	c = free.pop()
	for i in range(1, n + 1):
		if i == c:
			continue
		print(i, c)
