def readInts():
	str_input = input()
	return map(int, str_input.split())

n, m = readInts()

rows_free = n
columns_free = n

column_map = set()
row_map = set()

for _ in range(m):
	i, j = readInts()
	
	if not i in row_map:
		row_map.add(i)
		rows_free -= 1
		
	if not j in column_map:
		column_map.add(j)
		columns_free -= 1
	
	print(rows_free * columns_free)