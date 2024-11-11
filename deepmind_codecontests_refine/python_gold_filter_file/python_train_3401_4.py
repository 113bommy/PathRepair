def check(n,numsDone):
	currDist = 1
	currLen = 1
	currAns = [n]
	while (n + currDist <= 10**9) or (n - currDist >= -10**9):
		if (n+currDist) in numsDone and (n-currDist) in numsDone:
			currLen = 3
			currAns = [n-currDist,n,n+currDist]
			break
		elif (n+currDist) in numsDone:
			currLen = 2
			currAns = [n,n+currDist]
		elif (n-currDist) in numsDone:
			currLen = 2
			currAns = [n-currDist,n]
		currDist = currDist << 1
	return currAns


n = int(input())
nums = list(map(int, input().split()))
currLen = 1
currAns = [nums[0]]
numsDone = set(nums)

for i in nums:
	temp = check(i,numsDone)
	# print(i)
	# print(temp)
	if len(temp) > currLen:
		currLen = len(temp)
		currAns = temp
	if len(temp) == 3:
		break

print(currLen)
print(*currAns)