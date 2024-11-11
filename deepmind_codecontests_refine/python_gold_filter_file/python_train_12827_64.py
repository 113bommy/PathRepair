n = int(input())
ans = 0
for i in range(0, n):
	ans += 1/(n-i)
print(ans)