t, p = input(), input()
k, n, m = t.find('|'), len(t) - 1, len(p)

s = n + m
i = s // 2 - k

if s & 1 or i < 0 or i > m: print('Impossible')
else: print(p[: i] + t + p[i: ])