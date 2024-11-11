n = int(input())
count = 0
for _ in range(n):
	i, j = map(int, input().split())
	if j - i >= 2:
		count+=1
print(count)
