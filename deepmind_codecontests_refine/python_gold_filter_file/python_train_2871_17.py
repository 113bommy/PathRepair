n = int(input())
nums = list(map(int, input().split()))
m = n//2
for i in range(m):
    if i%2 == 0:
        nums[i], nums[n-i-1] = nums[n-i-1], nums[i]
for j in nums:
    print(j, end=' ')
