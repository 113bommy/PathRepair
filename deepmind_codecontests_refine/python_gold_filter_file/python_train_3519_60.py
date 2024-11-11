N, K = map(int, input().split())
V = list(map(int, input().split()))

vmax = 0
for l in range(0, K + 1):
	for r in range(0, K - l + 1):
		if N < l + r:
			break
		tv = V[:l] + V[N - r:]
		#print(tv)
		tv.sort()
		for n in range(min(len(tv), K - (l + r))):
			if tv[n] < 0:
				tv[n] = 0
		vmax = max(vmax, sum(tv))

print(vmax)
