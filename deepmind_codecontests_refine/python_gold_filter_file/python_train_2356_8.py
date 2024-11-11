n = int(input())

nums = list(map(int,input().strip().split(' ')))

ans = 0
for i in range(1,n-1):
	if (nums[i-1] < nums[i] and nums[i] > nums[i+1]) or (nums[i-1] > nums[i] and nums[i] < nums[i+1]):
		ans += 1

print(ans)