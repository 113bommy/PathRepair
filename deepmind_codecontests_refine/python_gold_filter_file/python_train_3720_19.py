#codeforces9C
gi = lambda : list(map(int,input().strip().split()))
nums = [int(e) for e in [bin(k)[2:] for k in range(1,1024)]]
n, = gi()
for k in range(len(nums)):
	if nums[k] > n:
		print(k)
		exit()
