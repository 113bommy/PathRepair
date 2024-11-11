
params = list(map(int, input().split()))

if(params[2] < params[0]):
	row = 1 + params[2]
	col = 1
else:
	params[2] -= params[0]
	row = params[0] - (params[2] // (params[1] - 1))

	nW = params[1] - 1 # 2
	params[2] %= 2*(nW - 1) + 2 # % 3
	if(params[2] < nW):
		col = 2 + params[2]
	else:
		col = 1 + nW - (params[2] - nW)

print("{} {}".format(row, col))