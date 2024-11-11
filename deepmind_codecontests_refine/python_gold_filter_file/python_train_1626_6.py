n = int(input())
a = [int(x) for x in input().split()]

r = 0
for i in range(len(a) + 1):
	x = a[:i].count(0)
	y = a[i:].count(1)
	r = max(r, x + y)
print(r)
