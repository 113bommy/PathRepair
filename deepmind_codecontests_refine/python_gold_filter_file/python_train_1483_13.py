n, m = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]

suf_sum = [0 for _ in range(m)]
suf_sum[-1] = l[-1]
for i in range(m - 2, -1, -1):
	suf_sum[i] = suf_sum[i + 1] + l[i]

if sum(l) < n:
	print(-1)
else:
	done = False
	for i in range(m):
		if l[i] + i > n:
			print(-1)
			done = True
			break
	if not done:
		p = [None for _ in range(m)]
		for i in range(m):
			p[i] = max(i, n - suf_sum[i])
		print(' '.join([str(_ + 1) for _ in p]))


