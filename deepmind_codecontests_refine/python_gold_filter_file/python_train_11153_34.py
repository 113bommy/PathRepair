n = int(input())
s = input()
arr = list(s)
c = 0
for i in range(1, n):
	if arr[i] == arr[i-1]:
		c += 1
		if i+1 < n:
			if arr[i] in ['R', 'G'] and arr[i+1] in ['R', 'G']:
				arr[i] = 'B'
			elif arr[i] in ['R', 'B'] and arr[i+1] in ['R', 'B']:
				arr[i] = 'G'
			elif arr[i] in ['B', 'G'] and arr[i+1] in ['B', 'G']:
				arr[i] = 'R'
		else:
			if arr[i] == 'R':
				arr[i] = 'G'
			elif arr[i] == 'G':
				arr[i] = 'B'
			else:
				arr[i] = 'R'

ans = "".join(arr)
print(c)
print(ans)
