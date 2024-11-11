from collections import Counter
h, w, n = [int(i) for i in input().split()]

vs = []
for i in range(-1, 2):
	for j in range(-1, 2):
		vs.append((i,j))
cnt = []
for _ in range(n):
	a, b = [int(i) for i in input().split()]
	for v in vs:
		aa = a + v[0]
		bb = b + v[1]
		if 2<=aa<=(h-1) and 2<=bb<=(w-1):
			cnt.append(aa*w+bb)

cnt = Counter(cnt)


cnt2 = [0] * 10
cnt2[0] = (h-2)*(w-2)
for k in cnt:
	c = cnt[k]
	cnt2[c] += 1
	cnt2[0] -= 1

for i in cnt2:
	print(i)



