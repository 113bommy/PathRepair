n, X = map(int, input().split())
x = list(map(int, input().split()))
x_sum = [0] # 1-indexed
for i in range(n):
	x_sum.append(x_sum[-1] + x[i])

ans = float("inf")
for i in range(1, n):
	res = X * (i + n)
	res += 5 * (x_sum[-1] - x_sum[-i - 1])
	cost = 5
	j = 1
	while (j * i) + i + 1 <= n:
		#print(-(j * i) - 1, -(j * i) - i - 1)
		res += cost * (x_sum[-(j * i) - 1] - x_sum[-(j * i) - i - 1])
		cost += 2
		j += 1
	res += cost * (x_sum[-(j * i) - 1])

	ans = min(res, ans)

print(ans)