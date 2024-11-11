n = int(input())
a = sorted(map(int, input().split())) + [0]
i, j = 0, -1
ans = 0
while j < n:
	i += 1
	j += 1
	while j < n and a[j] < i:
		j += 1
print(i - 1)