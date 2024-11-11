
def max_subarray(nums):
	curr_sum = nums[0]
	max_sum = nums[0]

	for i in range(1,len(nums)):
		curr_sum = max(nums[i],curr_sum+nums[i])

		if curr_sum > max_sum:
			max_sum = curr_sum
	return max_sum

n = input("")

n = int(n)

output = []
for i in range(n):

	new_n = input("")
	cc = input("")
	cc = cc.split(" ")
	cc_int = list(map(int,cc))
	output.append(cc_int)

for i in output:
	yasser = sum(i)
	adel1 = max_subarray(i[1:])
	adel2 = max_subarray(i[:-1])


	if yasser > adel1 and yasser > adel2:
		print("YES")
	else:
		print("NO")

