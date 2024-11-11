nc = list(map(int, input().split()))
nums = list(map(int, input().split()))
words = 1
for i in range(0, len(nums) - 1):
	if nums[i + 1] - nums[i] > nc[1]:
		words = 1
	else:
		words += 1

print(words)













