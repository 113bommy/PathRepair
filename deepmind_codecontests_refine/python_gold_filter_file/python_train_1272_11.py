onbits = [[] for i in range(33)]
n = int(input())
nums = [int(i) for i in input().split()]

for i in range(n):
	temp = bin(nums[i])[2:][::-1]
	for j in range(len(temp)):
		if temp[j] == '1':
			onbits[j].append(i)
onbits = onbits[::-1]
for i in onbits:
	if len(i) == 1:
		nums[0], nums[i[0]] = nums[i[0]], nums[0]
		break
print(' '.join([str(i) for i in nums]))