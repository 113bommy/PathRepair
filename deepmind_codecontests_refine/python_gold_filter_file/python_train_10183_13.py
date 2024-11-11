n, k = map(int, input().split())
td = [list(map(int, input().split())) for _ in range(n)]

td.sort(key=lambda x: x[1], reverse=True)

types = set()
can_remove = []
d_sm = 0

for t, d in td[:k]:
	d_sm += d
	if t in types:
		can_remove.append(d)
	else:
		types.add(t)

type_cnt = len(types)

ans = d_sm + type_cnt ** 2

left = td[k:][::-1]

while can_remove and left:
	t, d = left.pop()
	if t not in types:
		types.add(t)
		d_rmv = can_remove.pop()
		d_sm += d - d_rmv
		type_cnt += 1
		ans = max(ans, d_sm + type_cnt ** 2)

print(ans)
