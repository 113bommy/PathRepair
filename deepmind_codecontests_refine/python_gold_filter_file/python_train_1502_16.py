s = input()
n = list(map(int, input().split()))
p = list(map(int, input().split()))
m = int(input())

ps = s.count("B"), s.count("S"), s.count("C")

def solve(mid):
	return max(0, ps[0] * mid - n[0]) * p[0] + max(0, ps[1] * mid - n[1]) * p[1] + max(0, ps[2] * mid - n[2]) * p[2]

l = 0
r = m
mx = 0

for _ in range(r.bit_length()):
	mid = (l+r)//2
	c = solve(mid)
	if c > m:
		r = mid
	else:
		mx = max(mx, mid)
		l = mid

for mid in range(mx-10000, mx+10000):
	c = solve(mid)
	if c <= m:
		mx = max(mx, mid)
		

print(mx)
