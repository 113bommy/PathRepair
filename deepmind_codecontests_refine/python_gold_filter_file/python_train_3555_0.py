n = int(input())
s = sorted((v, i+1) for i, v in enumerate(map(int, input().split())))
t = sorted(map(int, input().split()))
r = []
q = []
err = False
for x, y in zip(s, t):
	d = x[0] - y
	if d < 0:
		q.append([-d, x[1]])
	else:
		while d > 0:
			if not q:
				err = True
				break
			if q[-1][0] <= d:
				z, i = q.pop()
				d -= z
				r.append((x[1], i, z))
			else:
				q[-1][0] -= d
				r.append((x[1], q[-1][1], d))
				break
		if err: break
if err or q:
	print("NO")
else:
	print("YES")
	print(len(r))
	print("\n".join(f"{b} {a} {d}" for a, b, d in r))