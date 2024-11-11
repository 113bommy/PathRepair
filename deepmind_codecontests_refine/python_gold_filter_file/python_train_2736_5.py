dic = {'1000':[1,1,1,2,2,2], '0100':[1,1,1,2,2,2], '0010':[1,1,1,2,2,1], '0001':[1,1,1,2,2,2], '0011': [1,1,1,2,2,1], '0110': [1,1,1,2,2,2], '0101': [1,1,1,2,2,1], '1001':[1,1,1,2,2,1], '1010':[1,1,1,2,2,2], '1100':[1,1,2,1,2,2], '0111':[1,2,2,1,2,2], '1011':[1,1,2,1,2,2], '1101':[1,1,1,2,2,2], '1110':[1,1,1,2,2,1], '1111':[1,1,1,2,2,1]	}
dic1 = {'1000':'0101', '0100':'1001', '0010':'1100', '0001': '1100', '0011': '1101', '0110':'1011', '0101':'1011', '1001': '0111', '1010':'0111', '1100': '0111', '0111':'0000', '1011':'0000', '1101':'0000', '1110':'0000', '1111':'0001' }
T = int(input())
while T > 0:
	n, m = map(int, input().split())
	matrix = []
	res = []
	for i in range(n):
		matrix.append(input())
	count = 0
	for i in range(n//2):
		row = i*2
		for j in range(m//2):
			col = j*2
			temp = matrix[row][col]+matrix[row][col+1]+matrix[row+1][col]+matrix[row+1][col+1]
			while temp != '0000':
				xx = dic[temp].copy()
				xx[0], xx[2], xx[4] = xx[0]+row, xx[2]+row, xx[4]+row
				xx[1], xx[3], xx[5] = xx[1]+col, xx[3]+col, xx[5]+col
				res.append(xx)
				temp = dic1[temp]
				count += 1
		if m%2 == 1:
			temp = '0'+matrix[row][m-1]+'0'+matrix[row+1][m-1]
			while temp != '0000':
				xx = dic[temp].copy()
				xx[0], xx[2], xx[4] = xx[0]+row, xx[2]+row, xx[4]+row
				xx[1], xx[3], xx[5] = xx[1]+m-2, xx[3]+m-2, xx[5]+m-2
				res.append(xx)
				temp = dic1[temp]
				count += 1
	if n%2 == 1:
		for i in range(m//2):
			col = i*2
			temp = '0'+'0'+matrix[n-1][col]+matrix[n-1][col+1]
			while temp != '0000':
				xx = dic[temp].copy()
				xx[0], xx[2], xx[4] = xx[0]+n-2, xx[2]+n-2, xx[4]+n-2
				xx[1], xx[3], xx[5] = xx[1]+col, xx[3]+col, xx[5]+col
				res.append(xx)
				temp = dic1[temp]
				count += 1
		if m%2 == 1 and matrix[n-1][m-1] == '1':
			temp = '0001'
			while temp != '0000':
				xx = dic[temp].copy()
				xx[0], xx[2], xx[4] = xx[0]+n-2, xx[2]+n-2, xx[4]+n-2 
				xx[1], xx[3], xx[5] = xx[1]+m-2, xx[3]+m-2, xx[5]+m-2
				res.append(xx)
				temp = dic1[temp]
				count += 1
	print(count)
	for r in res:
		print(*r)

	T -= 1