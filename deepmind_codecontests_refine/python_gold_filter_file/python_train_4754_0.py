N = 14
def possible_max(arr, pos):
	val = arr[pos]
	int_part = val // N
	float_part = val % N
	
	count = 0 
	for i, el in enumerate(arr):
		tmp = el + int_part
		if i == pos:
			tmp -= val
		if pos < i and i <= pos+float_part:
			tmp += 1
		if pos+float_part>=N and i <=(pos+float_part)%N:
			tmp += 1
		if tmp%2==0:
			count += tmp
	return count

line = input()
arr = list(map(int, line.split()))

count = 0
for i, el in enumerate(arr):
	if el%2==0:
		count += el

max_val = 0
for i in range(N):
	if arr[i] == 0:
		cur_val = count
	else:
		cur_val = possible_max(arr, i)
	if cur_val > max_val:
		max_val = cur_val

print(max_val)