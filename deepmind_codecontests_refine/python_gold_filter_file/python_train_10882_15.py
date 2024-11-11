n, m = map(int, input().split())
was = [False]*200001
for x in map(int, input().split()):
	if x <= 200000:
		was[x] = True
res = []
for i in range(1,10000000):
	if i > m:
		break
	if not was[i]:
		m -= i
		res.append(i)
print(len(res))
print(*res)
