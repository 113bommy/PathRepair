n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
ans = 1
if n <= m:
	i, j = 0, 0
	while i < n:
		j = i + 1
		while j < n:
			ans *= abs(a[i] - a[j])
			ans %= m
			j += 1
		i += 1
else :
	ans = 0
print(ans)
