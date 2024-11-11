n = int(input())
l = sorted([abs(int(i)) for i in input().split()])
ans = 0
i, j = 0, 0

while i < n:
	while j < n and l[i] + l[i] >= l[j]:
		j += 1
	ans += j - i - 1
	i += 1

print(ans)