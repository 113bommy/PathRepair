n = int(input())

inp = []
for i in range(n):
	inp.append(input())
inp_len = len(inp[0])

# check impossible
needle = inp[0]
possible = True
for i in range(1, n):
	tmp = 2 * inp[i]
	if needle not in tmp:
		possible = False
		break
	
if possible:
	min_rotation = 1234567890 # init
	H = 2 * inp[0]
	for m in range(inp_len):
		N = H[m:m + inp_len]
		num_rotation = 0
		for line in inp:
			tmp_h = 2 * line
			pnt = tmp_h.find(N)
			num_rotation += pnt
		# print(m, num_rotation)
		min_rotation = min(min_rotation, num_rotation)
	if min_rotation == 1234567890:
		print(0)
	else:
		print(min_rotation)
else:
	print(-1)
		
