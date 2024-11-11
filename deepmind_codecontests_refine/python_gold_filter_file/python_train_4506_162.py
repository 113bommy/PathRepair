import math
for t in range(int(input())):
	nums = list(map(int, input().split()))
	x = max(nums[2], nums[0])
	y = nums[1]
	output = math.sqrt(x**2 + y**2)
	print(round(output))