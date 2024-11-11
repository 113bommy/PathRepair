n, x0 = list(map(int, input().split()))

runners = []
for i in range(0, n):
	r = list(map(int, input().split()))
	runners.append(set(list(range(min(r[0], r[1]), max(r[0], r[1]) + 1))))

pos = set.intersection(*runners)

minDist = 10000
for p in pos:
	d = abs(x0 - p)
	if (d < minDist): minDist = d

if (minDist == 10000): minDist = -1

print(minDist)

