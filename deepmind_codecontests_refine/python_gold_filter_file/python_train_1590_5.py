n = int(input())
a = list(map(int,input().split()))
a.sort()
ans = 99999999999999999999999999999999999999999999999999999999999
for c in range(0, 100000):
	tec = 0
	for i in range(n):
		if c ** i > int(1e18):
			break
		tec += abs(a[i] - c ** i)
	ans = min(ans, tec)
print(ans)
