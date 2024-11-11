def knightFields(i,j):
	result, pos =[], [(i+2, j+1), (i+2, j-1), (i-2, j+1), (i-2, j-1), (i+1, j+2), (i-1, j+2), (i+1, j-2), (i-1, j-2)]
	for k in range(8):
		if pos[k][0] >= 0 and pos[k][1] >= 0 and pos[k][0] < 8 and pos[k][1] < 8: result.append(pos[k])
	#print(result)
	return result;

rook,knight,textToInt = input(),input(),{'a':0,'b':1,'c':2,'d':3,'e':4,'f':5,'g':6,'h':7}
rook = (textToInt[rook[0]], int(rook[1])-1)
knight = (textToInt[knight[0]], int(knight[1])-1)
fields = [[True for _ in range(8)] for __ in range(8)]
fields[knight[0]][knight[1]] =False
for i in range(8):
	for j in range(8):
		if i == rook[0]: fields[i][j] = False
		elif j == rook[1]: fields[i][j] = False
for field in knightFields(knight[0],knight[1]):
	fields[field[0]][field[1]] = False
for field in knightFields(rook[0],rook[1]):
	fields[field[0]][field[1]] = False
count = 0
for field in fields:
#	print(field)
	for f in field: 
		if f: count +=1
print(count)
