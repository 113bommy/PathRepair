n = int(input())

nums = {}

for i in range(1,n+1):

	t = list(map(int,input().split()))

	nums[i] = t



def check(a,b,n,nums):


	output = []
	nxt = None
	while len(output) != n:
		if nums[a][0] == b:
			nxt = nums[a][1]
		elif nums[a][1] == b:
			nxt = nums[a][0]
		else:
			return

		output.append(nxt)

		a = b
		b = nxt
	print(*output)
	exit()




check(1,nums[1][0],n,nums)
check(1,nums[1][1],n,nums)

