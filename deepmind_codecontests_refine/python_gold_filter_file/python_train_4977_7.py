n, m = map(int, input().split())
t = [list(map(int, input().split())) for _ in range(n)]
t.sort(key=lambda x:(x[1]*x[0] + x[2]*(m-x[0])), reverse=True)
full = [x[1]*x[0] + x[2]*(m-x[0]) for x in t]
cum = [0]
for i in range(n):
	cum.append(cum[-1] + full[i])
aoki = sum([p[0]*p[1] for p in t])
ans = n*m
for i in range(n):
	ok, ng = n*m, -1
	while ok-ng > 1:
		x = (ok+ng) // 2
		res = cum[x//m]
		if (x//m)-1 >= i:
			res -= full[i]
			res += full[x//m]
		res += t[i][1] * min(t[i][0], x%m) + t[i][2] * max(0, (x%m) - t[i][0])
		if res >= aoki:
			ok = x
		else:
			ng = x
	ans = min(ans, ok)
print(ans)