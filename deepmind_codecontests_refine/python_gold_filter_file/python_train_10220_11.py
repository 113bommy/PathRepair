q = int(input())

for i in range(q):
	n, k = map(int, input().split())
	price = list(map(int, input().split()))
	mi, ma = 0, 2 * 10 ** 8 + 1

	for j in range(n):
		min_temp = price[j] - k
		max_temp = price[j] + k
		if min_temp > mi:
			mi = min_temp
		if max_temp < ma:
			ma = max_temp

	if mi > ma:
		print(-1)
	else:
		print(ma)
