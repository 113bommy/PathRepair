data = [int(info) for info in input().split(' ')]

result = 0

if data[1] <= data[0]:
	data[1], data[0] = data[0], data[1]
	

if data[1] >= data[0]:
	result += data[0]
	if data[0] + data[1] > data[2]:
		result += data[2]
	else:
		result += data[0] + data[1]
	if data[1] > data[2] + data[0]:
		result += data[2] + data[0]
	else:
		result += data[1]
print(result)
