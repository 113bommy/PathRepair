input()
data = input() + 'W'

count = 0
literal_count = []
so_far = 0
for i in data:
	if i == 'B':
		so_far += 1
	if i == 'W':
		if so_far != 0:
			literal_count.append(so_far)
			so_far = 0
			count += 1



print(count)
print(' '.join(str(lit) for lit in literal_count))
