
import itertools, sys

n, k = [int(x) for x in input().split()]

perms = zip(*[[int(''.join(p)) for p in itertools.permutations(input())] for y in range(n)])

perms = list(perms)

# print(perms)

minimum = float("inf")

for p in perms:

	temp = max(p) - min(p)

	if temp < minimum:
		minimum = temp

print(minimum)