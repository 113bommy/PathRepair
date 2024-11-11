# x = [int(x) for x in input().split()]
q = int(input())


def solve():
	n = int(input())
	min_x, max_x, min_y, max_y = -100000,100000,-100000,100000

	for _ in range(n):
		x,y,f1,f2,f3,f4 = [int(x) for x in input().split()]

		if f1 == 0:
			min_x = max(min_x, x)
		if f2 == 0:
			max_y = min(max_y, y)
		if f3 == 0:
			max_x = min(max_x, x)
		if f4 == 0:
			min_y = max(min_y, y)

	if min_x > max_x or min_y > max_y:
		print(0)
	else:
		print(1, min_x, min_y)

for _ in range(q):
	solve()