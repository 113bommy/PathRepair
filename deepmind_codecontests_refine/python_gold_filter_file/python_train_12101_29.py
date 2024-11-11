arr = [0,1,3]

i = 4
while True:
	nth = i*(i-1) // 2
	if nth > 2*1e9:
		arr.append(nth)
		break
	arr.append(nth)
	i += 1 
# print('arr[-1]:',arr[-1])

t = int(input())
for _ in range(t):
	n, k = list(map(int, input().split()))
	string = ['a'] * n 
	chunk_no = -1 
	for i in range(len(arr)):
		if arr[i] >= k:
			chunk_no = i
			# print(arr[:i],' at i=',i)
			break
	left_b = (n-1) - chunk_no
	right_b = (k - arr[chunk_no - 1])
	# print(chunk_no, left_b, right_b)
	string[left_b] = 'b'
	string[-right_b] = 'b'
	print(''.join(string))
