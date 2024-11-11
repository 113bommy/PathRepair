N = int(input())
t = list(map(int,input().split()))
v = list(map(int,input().split()))

v.append(0)
interval = 0.5
total_t = sum(t)
now_t = 0
now_v = 0
T = [sum(t[:i]) for i in range(1,N+1)]
now_n = 0
d = 0
d_int = 0
while now_t < total_t:
	nxt_t, nxt_v = T[now_n], v[now_n + 1]
	delta_t, delta_v = nxt_t - now_t, nxt_v - now_v
	rest_t = [T[i]-now_t for i in range(N)]
	if now_v < v[now_n]:
		if delta_t + delta_v == 0:
			a = -1
		else:
			a = 1
	elif now_v == v[now_n]: 
		if delta_t + delta_v == 0:
			a = -1
		else:
			a = 0
	for i in range(N):
		rest = rest_t[i]
		if rest > 0:
			d_v = now_v - v[i+1]
			if rest == d_v:
				a = -1

	d_int += 2 * int(now_v * 2) + a
	d += now_v * interval + 1/2 * a * interval * interval
	now_t += interval
	now_v += a * interval
	if now_t == T[now_n]:
		now_n += 1

print(d)