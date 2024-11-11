n = int(input())
num_list = sorted(list(map(int, input().split())))
middle = num_list[n]

for _ in range(n - 1, -1, -1):
	if num_list[_] == middle:
		print('NO')
		exit(0)

print('YES')