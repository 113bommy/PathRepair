n = int(input())
a = [int(x) for x in input().split()]
best = -10**6
for x in a:
	is_perfect_square = False
	for d in range(1000+1):
		if d*d==x:
			is_perfect_square = True
	if not is_perfect_square:
		best = max(best,x)
print(best)