from itertools import combinations

n = int(input())
weights = list(map(int, input().split(' ')))
weights = sorted(weights)
best = float('inf')

for (first, second) in combinations(range(len(weights)), 2):
	result = weights[0:first] + weights[first + 1:second] + weights[second + 1:len(weights)]
	it = iter(result)
	total = 0
	for _ in range(int(len(result) / 2)):
		total += sum([abs(next(it) - next(it))])
	best = min(best, total)

print(best)