def get_sum(leng, cube):
	if leng == 1:
		return 0, 0, cube[0][0]
	
	if 0 in cube[0]:
		sum_v = sum(cube[1])
	else:
		sum_v = sum(cube[0])
		
	posx = -1
	for line in range(0, leng):
		if posx == -1 and 0 in cube[line]:
			posx = cube[line].index(0)
			posy = line
			continue
		if sum_v != sum(cube[line]):
			return -1, -1, -1
	for col in [[cube[i][ii] for i in range(leng)] for ii in range(leng)]:
		if sum_v != sum(col) and 0 not in col:
			return -1, -1, -1
	if posx != posy and sum_v != sum([cube[i][i] for i in range(leng)]):
		return -1, -1, -1
	if leng - posx-1 != posy and sum_v != sum([cube[leng - i-1][i] for i in range(leng)]):
		return -1, -1, -1
	return posx, posy, sum_v

leng = int(input().strip())
cube = [list(map(int, input().strip().split())) for i in range(leng)]

posx, posy, sumv = get_sum(leng, cube)
if posx == 0 and posy == 0 and sumv == 0:
	print(999)
elif posx == -1 or sum(cube[posy]) != sum([cube[i][posx] for i in range(leng)]):
	print(-1)
elif posx == posy and sum(cube[posy]) != sum([cube[i][i] for i in range(leng)]):
	print(-1)
elif leng-1-posx == posy and sum(cube[posy]) != sum([cube[leng-1-i][i] for i in range(leng)]):
	print(-1)
elif sumv - sum(cube[posy]) <= 0:
	print(-1)
else:
	print(sumv - sum(cube[posy]))