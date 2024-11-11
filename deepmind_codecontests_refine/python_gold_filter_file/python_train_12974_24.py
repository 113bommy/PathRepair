n, t = map(int, input().split())

ans = 0

for day in input().split():
	ans += 1
	t -= 86400 - int(day)
	if t <= 0:
		print(ans)
		break