tt = int(input())
for i in range(tt):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	new = set()
	h = 0
	t = 0
	for j in range(len(b)):
		if b[j] in new:
			t += 1
			continue
		while b[j] not in new:
			new.add(a[h])
			h += 1
		t += 2 * (h - j - 1) + 1
	print(t)
