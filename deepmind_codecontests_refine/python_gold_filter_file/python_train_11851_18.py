n = int(input())
if n == 3:
	print(2, 3, 25)
	exit()
if n == 4:
	print(2, 3, 4, 9)
	exit()
ans = [2, 4, 6, 3, 9]
c = 5
M = 4
while c + 1 < n and M + 6 < 30000:
	c += 2
	ans += [M + 4, M + 6]
	M += 6
c = len(ans)
M = 9
while c + 1 < n and M + 6 < 30000:
	c += 2
	ans += [M + 6, M + 12]
	M += 12
ans += [x * 6 for x in range(2, n - c + 2)]
print(*ans)