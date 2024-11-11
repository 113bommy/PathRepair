def ceil(m):
	m_floor = int(m // 1)
	diff = m - m_floor
	if diff > 0:
		return m_floor + 1
	else:
		return m_floor


hh, mm = list(map(int, input().split()))

h, d, c, n = list(map(int, input().split()))

dt_m = (60 - mm)
dt_h = (20 - hh)

if dt_h <= 0:
	dt = 0
else:
	dt = (dt_h - 1) * 60 + dt_m

if dt > 0:
	wait_h = (h + dt * d)
	cost = min(.8 * (ceil(wait_h / n)) * c, (ceil(h / n)) * c)
else:
	cost = .8 * (ceil(h / n)) * c

print("{0:.4f}".format(cost))
