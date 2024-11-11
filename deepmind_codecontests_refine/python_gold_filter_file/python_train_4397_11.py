def solve(n, a, b):
	a.sort()
	b.sort()
	return a, b

t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	l1, l2 = solve(n, a, b)
	print(" ".join(map(str, l1)))
	print(" ".join(map(str, l2)))
