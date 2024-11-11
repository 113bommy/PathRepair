def change(arr, i, j):
	if arr[i][j] == 0:
		arr[i][j] = 1
	else:
		arr[i][j] = 0
	return arr

lights = [[1, 1, 1, 1, 1] for j in range(5)]
arr = [[int(j) for j in input().split()] for x in range(3)]

for i in range(3):
	for j in range(3):
		num = arr[i][j]	% 2
		while num != 0:
			lights = change(lights, i+1, j+1)
			lights = change(lights, i, j+1)
			lights = change(lights, i+2, j+1)
			lights = change(lights, i+1, j)
			lights = change(lights, i+1, j+2)
			num -= 1

for x in range(1, 4):
	for y in range(1, 4):
		print(lights[x][y], end = '')
	print('')
